#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "turtlesim/srv/kill.hpp"
#include "turtlesim/srv/spawn.hpp"
#include "my_robot_interfaces/action/move_turtle.hpp"
#include "geometry_msgs/msg/twist.hpp"

using TurtleSpawn = turtlesim::srv::Spawn;
using TurtleKill = turtlesim::srv::Kill;
using Twist = geometry_msgs::msg::Twist;
using MoveTurtle = my_robot_interfaces::action::MoveTurtle;
using MoveTurtleGoalHandle = rclcpp_action::ServerGoalHandle<MoveTurtle>;

using namespace std::placeholders;
using namespace std::chrono_literals;

using LifecycleCallbackReturn = 
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

namespace turtle_controller{

class TurtleController : public rclcpp_lifecycle::LifecycleNode
{
public:
    TurtleController(const rclcpp::NodeOptions &options) : LifecycleNode("turtle_controller_cpp", options)
    {
        cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

        this->declare_parameter("turtle_name", rclcpp::PARAMETER_STRING);

        server_activated_ = false;
        
    }

    LifecycleCallbackReturn on_configure(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;

        turtle_name_ = this->get_parameter("turtle_name").as_string();

        spawn_turtle_client_ = this->create_client<TurtleSpawn>(
            "/spawn", rclcpp::QoS(10), cb_group_);
        kill_turtle_client_ = this->create_client<TurtleKill>(
            "/kill", rclcpp::QoS(10), cb_group_);

        cmd_vel_publisher_ = this->create_publisher<Twist>("/" + turtle_name_ + "/cmd_vel", 10);

        move_turtle_server_ = rclcpp_action::create_server<MoveTurtle>(
            this,
            "move_turtle_" + turtle_name_,
            std::bind(&TurtleController::goal_callback, this, _1, _2),
            std::bind(&TurtleController::cancel_callback, this, _1),
            std::bind(&TurtleController::handle_accepted_callback, this, _1),
            rcl_action_server_get_default_options(),
            cb_group_);
        RCLCPP_INFO(this->get_logger(), "Action server has been started!!");

        // Call function
        spawn_turtle();
        
        return LifecycleCallbackReturn::SUCCESS;
    }

    LifecycleCallbackReturn on_cleanup(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        
        // Delate turtle
        kill_turtle();

        // Delate clients, publisher and action
        spawn_turtle_client_.reset();
        kill_turtle_client_.reset();
        cmd_vel_publisher_.reset();
        move_turtle_server_.reset();
        
        return LifecycleCallbackReturn::SUCCESS;
    }

    LifecycleCallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state)
    {
        server_activated_ = true;
        rclcpp_lifecycle::LifecycleNode::on_activate(previous_state);
        return LifecycleCallbackReturn::SUCCESS;
    }

    LifecycleCallbackReturn on_deactivate(const rclcpp_lifecycle::State &previous_state)
    {
        server_activated_ = false;
        rclcpp_lifecycle::LifecycleNode::on_deactivate(previous_state);
        return LifecycleCallbackReturn::SUCCESS;
    }

    LifecycleCallbackReturn on_shutdown(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;

        server_activated_ = false;
        // Delate turtle
        kill_turtle();
        
        // Delate clients, publisher and action
        spawn_turtle_client_.reset();
        kill_turtle_client_.reset();
        cmd_vel_publisher_.reset();
        move_turtle_server_.reset();
        
        return LifecycleCallbackReturn::SUCCESS;
    }

private:
    rclcpp_action::GoalResponse goal_callback(
        const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const MoveTurtle::Goal> goal)
    {
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received a new goal!!");

        // Check if node is "activated"
        if (!server_activated_)
        {
            RCLCPP_WARN(this->get_logger(), "Action server not activated yet!!");
            return rclcpp_action::GoalResponse::REJECT;
        }
        

        // Goal policy
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (goal_handle_)
            {
                if (goal_handle_->is_active())
                {
                    RCLCPP_WARN(this->get_logger(), "Current goal still active");
                    return rclcpp_action::GoalResponse::REJECT;
                }
                
            }
            
        }

        // Validate a new goal
        if ((fabs(goal->linear_vel_x) > 3.0) ||
            (fabs(goal->angular_vel_z) > 2.0) ||
            (goal->duration_sec <= 0.0))
        {
            return rclcpp_action::GoalResponse::REJECT;
        }
        

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse cancel_callback(
        const std::shared_ptr<MoveTurtleGoalHandle> goal_handle)
    {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "Received cancel request");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted_callback(
        const std::shared_ptr<MoveTurtleGoalHandle> goal_handle)
    {
        execute_goal(goal_handle);
    }

    void execute_goal(
        const std::shared_ptr<MoveTurtleGoalHandle> goal_handle)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            this->goal_handle_ = goal_handle;
        }
        double linear_vel_x  = goal_handle->get_goal()->linear_vel_x;
        double linear_vel_y  = goal_handle->get_goal()->linear_vel_y;
        double angular_vel_z = goal_handle->get_goal()->angular_vel_z;
        int duration_sec     = goal_handle->get_goal()->duration_sec;

        auto result = std::make_shared<MoveTurtle::Result>();
        auto start = now();
        auto duration = rclcpp::Duration(duration_sec, 0);
        rclcpp::Rate rate(10);

        while (rclcpp::ok())
        {
            if (now() - start > duration)
            {
                auto msg = Twist();
                msg.linear.x  = linear_vel_x;
                msg.linear.y  = linear_vel_y;
                msg.angular.z = angular_vel_z;
                cmd_vel_publisher_->publish(msg);
                result->success = true;
                result->message = "Success";
                goal_handle->succeed(result);
                return;
            }

            if (!server_activated_)
            {
                auto msg = Twist();
                msg.linear.x  = linear_vel_x;
                msg.linear.y  = linear_vel_y;
                msg.angular.z = angular_vel_z;
                cmd_vel_publisher_->publish(msg);
                result->success = false;
                result->message = "Aborted because server was deactivated!";
                goal_handle->abort(result);
                return;
            }
            
            
            auto msg = Twist();
            msg.linear.x = linear_vel_x;
            msg.linear.y = linear_vel_y;
            msg.angular.z = angular_vel_z;
            cmd_vel_publisher_->publish(msg);
            rate.sleep();
        }
        
    }

    void spawn_turtle()
    {
        spawn_turtle_client_->wait_for_service();
        auto request = std::make_shared<TurtleSpawn::Request>();
        request->name = turtle_name_;
        request->x = 5.0;
        request->y = 5.0;
        request->theta = 0.0;
        RCLCPP_INFO(this->get_logger(), "Trying to spawn turtle");
        auto result = spawn_turtle_client_->async_send_request(request);
        RCLCPP_INFO(this->get_logger(), "New spawned turtle: %s", result.get()->name.c_str());

        // std::this_thread::sleep_for(std::chrono::seconds(3));
        // kill_turtle_thread_ = std::thread(std::bind(&TurtleController::kill_turtle, this));
    }

    void kill_turtle()
    {
        kill_turtle_client_->wait_for_service();
        auto request = std::make_shared<TurtleKill::Request>();
        request->name = turtle_name_;
        RCLCPP_INFO(this->get_logger(), "Trying to remove turtle");
        kill_turtle_client_->async_send_request(request);
        RCLCPP_INFO(this->get_logger(), "Turtle has been removed");
    }

    std::string turtle_name_;

    rclcpp::Client<TurtleSpawn>::SharedPtr spawn_turtle_client_;
    rclcpp::Client<TurtleKill>::SharedPtr kill_turtle_client_;
    rclcpp_action::Server<MoveTurtle>::SharedPtr move_turtle_server_;
    rclcpp::Publisher<Twist>::SharedPtr cmd_vel_publisher_;

    std::shared_ptr<MoveTurtleGoalHandle> goal_handle_;
    std::mutex mutex_;

    rclcpp::CallbackGroup::SharedPtr cb_group_;

    bool server_activated_;
};

} // namespace

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(turtle_controller::TurtleController)
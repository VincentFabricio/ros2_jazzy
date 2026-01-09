#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_robot_interfaces/action/move_turtle.hpp"

using MoveTurtle = my_robot_interfaces::action::MoveTurtle;
using MoveTurtleGoalHandle = rclcpp_action::ClientGoalHandle<MoveTurtle>;
using namespace std::placeholders;

class MoveTurtleClient : public rclcpp::Node
{
public:
    MoveTurtleClient() : Node("move_turtle_client_cpp")
    {
        this->declare_parameter("turtle_name", rclcpp::PARAMETER_STRING);
        turtle_name_ = this->get_parameter("turtle_name").as_string();

        move_turtle_client_ = rclcpp_action::create_client<MoveTurtle>(
            this, turtle_name_);
    }

    void send_goal()
    {
        move_turtle_client_->wait_for_action_server();


        // Create a goal
        auto goal = MoveTurtle::Goal();
        goal.linear_vel_x = 0.0;
        goal.linear_vel_y = 0.0;
        goal.angular_vel_z = 0.0;
        goal.duration_sec  = 1.0;

        // Add callbacks
        auto options = rclcpp_action::Client<MoveTurtle>::SendGoalOptions();
        options.result_callback = std::bind(&MoveTurtleClient::goal_result_callback, this, _1);
        // Send goal
        RCLCPP_INFO(this->get_logger(), "Sending a goal 1");
        move_turtle_client_->async_send_goal(goal, options);
        std::this_thread::sleep_for(std::chrono::seconds(10));

        goal.linear_vel_x = 0.2;
        goal.linear_vel_y = 0.2;
        goal.angular_vel_z = 0.0;
        goal.duration_sec  = 1.0;

        RCLCPP_INFO(this->get_logger(), "Sending a goal 2");
        move_turtle_client_->async_send_goal(goal, options);
        std::this_thread::sleep_for(std::chrono::seconds(2));

        goal.linear_vel_x = 0.5;
        goal.linear_vel_y = 0.5;
        goal.angular_vel_z = 1.0;
        goal.duration_sec  = 1.0;

        RCLCPP_INFO(this->get_logger(), "Sending a goal 3");
        move_turtle_client_->async_send_goal(goal, options);
        std::this_thread::sleep_for(std::chrono::seconds(4));

        goal.linear_vel_x = 0.2;
        goal.linear_vel_y = 0.2;
        goal.angular_vel_z = 0.0;
        goal.duration_sec  = 1.0;

        RCLCPP_INFO(this->get_logger(), "Sending a goal 4");
        move_turtle_client_->async_send_goal(goal, options);
        std::this_thread::sleep_for(std::chrono::seconds(2));

        goal.linear_vel_x = 0.0;
        goal.linear_vel_y = 0.0;
        goal.angular_vel_z = 0.0;
        goal.duration_sec  = 1.0;

        RCLCPP_INFO(this->get_logger(), "Sending a goal 5");
        move_turtle_client_->async_send_goal(goal, options);
        std::this_thread::sleep_for(std::chrono::seconds(2));

    }

private:
    // Callback to receive the result
    void goal_result_callback(const MoveTurtleGoalHandle::WrappedResult &result)
    {
        auto status = result.code;
        if (status == rclcpp_action::ResultCode::SUCCEEDED)
        {
            RCLCPP_INFO(this->get_logger(), "Succeded");
        }
        else if (status == rclcpp_action::ResultCode::ABORTED)
        {
            RCLCPP_ERROR(this->get_logger(), "Aborted");
        }
        else if (status == rclcpp_action::ResultCode::CANCELED)
        {
            RCLCPP_WARN(this->get_logger(), "Canceled");
        }

        bool state = result.result->success;
        std::string message = result.result->message;
        RCLCPP_INFO(this->get_logger(), "State: %s, Message: %s", state ? "true" : "false", message.c_str());
    }

    std::string turtle_name_;
    rclcpp_action::Client<MoveTurtle>::SharedPtr move_turtle_client_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MoveTurtleClient>();
    node->send_goal();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
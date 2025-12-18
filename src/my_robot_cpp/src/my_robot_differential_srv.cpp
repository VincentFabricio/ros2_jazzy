#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "my_robot_interfaces/srv/my_robot_srv.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include <string>

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

class DifferencialNodeSrv : public rclcpp::Node
{
public:
    DifferencialNodeSrv() : Node("differential_node_srv") 
    {
        publisher1 = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        timer1 = this->create_wall_timer(
            std::chrono::milliseconds(500),
            std::bind(&DifferencialNodeSrv::timer_callback_diff, this));
        subscriber_sensor = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states", 10, std::bind(&DifferencialNodeSrv::subscriber_callback_sensors, this, _1));
        server1 = this->create_service<my_robot_interfaces::srv::MyRobotSrv>(
            "joints_actions", std::bind(&DifferencialNodeSrv::srv_callback_actions, this, _1, _2));
        client1 = this->create_client<my_robot_interfaces::srv::MyRobotSrv>("joints_actions");
        while (!client1->wait_for_service(1s))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for Service Server to be up...");
        }
        RCLCPP_INFO(this->get_logger(), "Differential Enable!!");
    }
 
private:
    
    void timer_callback_diff()
    {
        geometry_msgs::msg::Twist msg;
        if ((start_var == 0) && (msgs_sended == 0))
        {
            call_actions("diffok", 0.0, 0.0, 0.0, 0.0);
            msgs_sended = 1;
        }
        

        if ((start_var == 1) && (action_move == 1))
        {
            // set_velocity = 0.25;
            // error = set_velocity - (left_vel+right_vel)/2;
            // integral = error * 0.1;
            // derivative = (error - d_error)/0.1;
            // u_signal = Kp*error + Ki*integral + Kd*derivative;
            // d_error = error;
            // msg.linear.x = u_signal;
            msg.linear.x = 0.25;
            publisher1 -> publish(msg);
            move_counter ++;
            if (move_counter >= 40)
            {
                action_move = 0;
                move_counter = 0;
                // Enviar mensaje
                msg.linear.x = 0.0;
                publisher1 -> publish(msg);
                call_actions("diffoff1", 0.0, 0.0, 0.0, 0.0);
            }
            RCLCPP_INFO(this->get_logger(), 
                "Linear: x=%.2f, y=%.2f, z=%.2f | Angular: x=%.2f, y=%.2f, z=%.2f",    
                msg.linear.x, msg.linear.y, msg.linear.z,
                msg.angular.x, msg.angular.y, msg.angular.z);
        }
        else if ((start_var == 1) && (action_move == 2))
        {
            msg.linear.x = 0.25;
            msg.angular.z = 0.25;
            publisher1 -> publish(msg);
            move_counter ++;
            if (move_counter >= 5)
            {
                action_move = 0;
                move_counter = 0;
                // Mensaje
                msg.linear.x = 0.0;
                msg.angular.z = 0.0;
                publisher1 -> publish(msg);
                call_actions("diffoff2", 0.0, 0.0, 0.0, 0.0);
            }
            
        }
        else if ((start_var == 1) && (action_move == 3))
        {
            // set_velocity = 0.25;
            // error = set_velocity - (left_vel+right_vel)/2;
            // integral = error * 0.1;
            // derivative = (error - d_error)/0.1;
            // u_signal = Kp*error + Ki*integral + Kd*derivative;
            // d_error = error;
            // msg.linear.x = u_signal;
            msg.linear.x = 0.25;
            publisher1 -> publish(msg);
            move_counter ++;
            if (move_counter >= 20)
            {
                action_move = 0;
                move_counter = 0;
                // Enviar mensaje
                msg.linear.x = 0.0;
                publisher1 -> publish(msg);
                call_actions("diffoff3", 0.0, 0.0, 0.0, 0.0);
            }
            
        }
        else if ((start_var == 1) && (action_move == 4))
        {
            msg.linear.x = 0.25;
            msg.angular.z = -0.25;
            publisher1 -> publish(msg);
            move_counter ++;
            if (move_counter >= 5)
            {
                action_move = 0;
                move_counter = 0;
                // Mensaje
                msg.linear.x = 0.0;
                msg.angular.z = 0.0;
                publisher1 -> publish(msg);
                call_actions("diffoff4", 0.0, 0.0, 0.0, 0.0);
            }
            // RCLCPP_INFO(this->get_logger(), 
            //     "Linear: x=%.2f, y=%.2f, z=%.2f | Angular: x=%.2f, y=%.2f, z=%.2f",    
            //     msg.linear.x, msg.linear.y, msg.linear.z,
            //     msg.angular.x, msg.angular.y, msg.angular.z);
            
        }
        else if ((start_var == 1) && (action_move == 5))
        {
            msg.linear.x = 0.25;
            publisher1 -> publish(msg);
            move_counter ++;
            if (move_counter >= 5)
            {
                action_move = 0;
                move_counter = 0;
                // Enviar mensaje
                msg.linear.x = 0.0;
                publisher1 -> publish(msg);
                call_actions("diffoff5", 0.0, 0.0, 0.0, 0.0);
            }
            
            
        }
        call_actions("diff", left_pos, left_vel, right_pos, right_vel);
        
    }
    // Subscriber Sensor
    void subscriber_callback_sensors(const sensor_msgs::msg::JointState::SharedPtr msg)
    {

        for (size_t i = 0; i < msg->name.size(); ++i) {
        if (msg->name[i] == "base_left_wheel_joint") 
        {
            left_pos = msg->position[i];
            left_vel = msg->velocity[i];
        } 
        else if (msg->name[i] == "base_right_wheel_joint") 
        {
            right_pos = msg->position[i];
            right_vel = msg->velocity[i];
        }
        }
        // RCLCPP_INFO(this->get_logger(), "Left Wheel= %.2f, Left Vel= %.2f",left_pos, left_vel);
        // RCLCPP_INFO(this->get_logger(), "Right Wheel= %.2f, Right Vel= %.2f",right_pos, right_vel);
    }
    // Server
    void srv_callback_actions(
        const std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv::Request> request,
        std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv::Response> response)
    {
        auto actions = request->actions;
        // RCLCPP_INFO(this->get_logger(), "Received: %s", actions.c_str());
        if (request->actions == "diffon1")
        {
            start_var = 1;
            action_move = 1;
        }
        else if (request->actions == "diffon2")
        {
            action_move = 2;
        }
        else if (request->actions == "diffon3")
        {
            action_move = 3;
        }
        else if (request->actions == "diffon4")
        {
            action_move = 4;
        }
        else if (request->actions == "diffon5")
        {
            action_move = 5;
        }
        
        if (!actions.empty())
        {
            response->success = true;
            return;
        }
        else
        {
            response->success = false;
            return;
        }
         
    }
    // Client
    void call_actions(std::string actions, double pos1, double vel1, double pos2, double vel2)
    {
        auto request = std::make_shared<my_robot_interfaces::srv::MyRobotSrv::Request>();
        request->actions = actions;
        request->pos1 = pos1;
        request->vel1 = vel1;
        request->pos2 = pos2;
        request->vel2 = vel2;
        
        auto future = client1->async_send_request(
            request, std::bind(&DifferencialNodeSrv::callback_actions, this, _1));
    }
    void callback_actions(rclcpp::Client<my_robot_interfaces::srv::MyRobotSrv>::SharedFuture future)
    {
        auto response = future.get();
        if (response -> success) {
            // RCLCPP_INFO(this->get_logger(), "Server Ok");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Goal accepted by server, waiting for result");
        }
    }
    std::int64_t action_move = 0;
    std::int64_t msgs_sended = 0;
    std::int64_t move_counter = 0;
    std::int64_t start_var = 0;
    double left_pos = 0.0;
    double left_vel = 0.0;
    double right_pos = 0.0;
    double right_vel = 0.0;
    double Kp = 1.5;
    double Ki = 0.0;
    double Kd = 0.0;
    double error = 0.0;
    double d_error = 0.0;
    double integral = 0.0;
    double derivative = 0.0;
    double u_signal = 0.0;
    double set_velocity = 0.5;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher1;
    rclcpp::TimerBase::SharedPtr timer1;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_sensor;

    rclcpp::Client<my_robot_interfaces::srv::MyRobotSrv>::SharedPtr client1;
    rclcpp::Service<my_robot_interfaces::srv::MyRobotSrv>::SharedPtr server1;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DifferencialNodeSrv>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
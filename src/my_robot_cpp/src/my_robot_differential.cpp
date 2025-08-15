#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int64.hpp"
 
class MyRobotDifferential : public rclcpp::Node 
{
public:
    MyRobotDifferential() : Node("my_robot_differential_cpp")
    {
        publisher1 = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        timer1 = this->create_wall_timer(
            std::chrono::milliseconds(250),
            std::bind(&MyRobotDifferential::timer_callback1, this));
        using std::placeholders::_1;
        subscriber_diff = this->create_subscription<std_msgs::msg::String>(
            "subs_diff", 10, std::bind(&MyRobotDifferential::subscriber_callback_diff, this, _1));
        publisher_msgs = this->create_publisher<std_msgs::msg::String>("actions_joints", 10);
        RCLCPP_INFO(this->get_logger(), "Differential");
    }
 
private:
    void subscriber_callback_diff(const std_msgs::msg::String::SharedPtr msg)
    {
        // std_msgs::msg::String joints_actions;
        // joints_actions.data = "Move arm";
        // publisher_msgs -> publish(joints_actions);
        RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg-> data.c_str());
        if (msg->data == "diffy1")
        {
            action_move = 1;
        }
        
    }
    void timer_callback1()
    {
        geometry_msgs::msg::Twist msg;

        if (start_var == 1)
        {
            std_msgs::msg::String joints_actions;
            joints_actions.data = "diffok";
            publisher_msgs -> publish(joints_actions);
            start_var=0;
        }
        


        if ((action_move ==1)&&(move_counter >= 0))
        {
            msg.linear.x = 0.5;
            msg.angular.z = 0.5;
            publisher1 -> publish(msg);
            move_counter ++;
            if (move_counter >= 10)
            {
                action_move = 0;
                move_counter = 0;
                std_msgs::msg::String joints_actions;
                joints_actions.data = "diffoff";
                publisher_msgs -> publish(joints_actions);
                msg.linear.x = 0.0;
                msg.angular.z = 0.0;
                publisher1 -> publish(msg);
            }
            RCLCPP_INFO(this->get_logger(), 
            "Linear: x=%.2f, y=%.2f, z=%.2f | Angular: x=%.2f, y=%.2f, z=%.2f",    
            msg.linear.x, msg.linear.y, msg.linear.z,
            msg.angular.x, msg.angular.y, msg.angular.z);
        }
        
        
        
    }
    std_msgs::msg::String joints_actions;
    std::int64_t action_move = 0;
    std::int64_t move_counter = 0;
    std::int64_t start_var = 1;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_diff;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_msgs;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher1;
    rclcpp::TimerBase::SharedPtr timer1;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyRobotDifferential>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
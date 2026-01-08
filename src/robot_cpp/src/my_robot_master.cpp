#include "rclcpp/rclcpp.hpp"
// #include "geometry_msgs/msg/twist.hpp"
 #include "std_msgs/msg/string.hpp"
// #include "std_msgs/msg/int64.hpp"
 
class MyRobotNode : public rclcpp::Node 
{
public:
    MyRobotNode() : Node("my_robot_master_cpp")
    {
        using std::placeholders::_1;
        subscriber1 = this->create_subscription<std_msgs::msg::String>(
            "actions_joints", 10, std::bind(&MyRobotNode::subscriber_callback, this, _1));
        publisher_diff = this->create_publisher<std_msgs::msg::String>("subs_diff", 10);

        publisher_j0 = this->create_publisher<std_msgs::msg::String>("subs_joint0", 10);
        publisher_j1 = this->create_publisher<std_msgs::msg::String>("subs_joint1", 10);
        RCLCPP_INFO(this->get_logger(), "Master");
    }
 
private:
    void subscriber_callback(const std_msgs::msg::String::SharedPtr msg1)
    {
        
        RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg1-> data.c_str());
        if ((msg1->data == "diffok") && (counter1 == 0))
        {
            std_msgs::msg::String msgs_master;
            msgs_master.data = "diffy1";
            publisher_diff -> publish(msgs_master);
            counter1 ++;
        }
        else if ((msg1->data == "diffoff") && (counter1 == 1))
        {
            std_msgs::msg::String msgs_master1;
            msgs_master1.data = "j0y1";
            publisher_j0 -> publish(msgs_master1);
            counter1 ++;
        }
        else if ((msg1->data == "j0off") && (counter1 == 2))
        {
            std_msgs::msg::String msgs_master2;
            msgs_master2.data = "j1y1";
            publisher_j1 -> publish(msgs_master2);
            counter1 ++;
        }
        
        
        
    }
    
    std_msgs::msg::String msgs_master;
    std::int64_t counter1 = 0;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber1;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_diff;

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_j0;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_j1;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyRobotNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
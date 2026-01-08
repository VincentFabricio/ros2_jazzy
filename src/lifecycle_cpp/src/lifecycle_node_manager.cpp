#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "example_interfaces/msg/int64.hpp"

using LifecycleCallbackReturn = 
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class NumberPublisherNode : public rclcpp_lifecycle::LifecycleNode
{
public:
    NumberPublisherNode() : LifecycleNode("number_publisher_node_cpp")
    {
        RCLCPP_INFO(this->get_logger(), "IN constructor");
        // Variables
        number_ = 1;
        publish_frequency = 1.0;
        
        
    }

    // Create ROS2 communications, connect to hardware
    LifecycleCallbackReturn on_configure(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        RCLCPP_INFO(this->get_logger(), "IN on_configure");
        // Create
        number_publisher_ = 
            this->create_publisher<example_interfaces::msg::Int64>("number", 10);

        number_timer_ = this->create_wall_timer(
            std::chrono::milliseconds((int)(1000.0 / publish_frequency)),
            std::bind(&NumberPublisherNode::publish_number, this));

        number_timer_->cancel();

        return LifecycleCallbackReturn::SUCCESS;
    }

    // Activate/Enable Hardware
    LifecycleCallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        RCLCPP_INFO(this->get_logger(), "IN on_activate");
        number_timer_->reset();

        rclcpp_lifecycle::LifecycleNode::on_activate(previous_state);
        return LifecycleCallbackReturn::SUCCESS;
    }

    // Destroy ROS2 communications, disconnect from Hardware
    LifecycleCallbackReturn on_cleanup(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        RCLCPP_INFO(this->get_logger(), "IN on_cleanup");
        number_publisher_.reset();
        number_timer_.reset();

        return LifecycleCallbackReturn::SUCCESS;
    }

private:
    void publish_number()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        number_publisher_->publish(msg);
        number_++;
    }

    double publish_frequency;
    int number_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node->get_node_base_interface());
    rclcpp::shutdown();
    return 0;
}
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class SingleThreadedExecutorNode : public rclcpp::Node
{
public:
    SingleThreadedExecutorNode() : Node("single_threaded_executor_cpp")
    {
        this->timer1_ = this->create_wall_timer(
            1000ms,
            std::bind(&SingleThreadedExecutorNode::callBackTimer1, this));
        this->timer2_ = this->create_wall_timer(
            1000ms,
            std::bind(&SingleThreadedExecutorNode::callBackTimer2, this));
        this->timer3_ = this->create_wall_timer(
            1000ms,
            std::bind(&SingleThreadedExecutorNode::callBackTimer3, this));
    }

private:

    void callBackTimer1()
    {
        std::this_thread::sleep_for(2000ms);
        RCLCPP_INFO(this->get_logger(), "cb 1");
    }

    void callBackTimer2()
    {
        std::this_thread::sleep_for(2000ms);
        RCLCPP_INFO(this->get_logger(), "cb 2");
    }

    void callBackTimer3()
    {
        std::this_thread::sleep_for(2000ms);
        RCLCPP_INFO(this->get_logger(), "cb 3");
    }

    rclcpp::TimerBase::SharedPtr timer1_;
    rclcpp::TimerBase::SharedPtr timer2_;
    rclcpp::TimerBase::SharedPtr timer3_;
    
};

class Node2 : public rclcpp::Node
{
public:
    Node2() : Node("node2")
    {
        this->timer4_ = this->create_wall_timer(
            1000ms,
            std::bind(&Node2::callBackTimer4, this));
        this->timer5_ = this->create_wall_timer(
            1000ms,
            std::bind(&Node2::callBackTimer5, this));
    }

private:

    void callBackTimer4()
    {
        std::this_thread::sleep_for(2000ms);
        RCLCPP_INFO(this->get_logger(), "cb 4");
    }

    void callBackTimer5()
    {
        std::this_thread::sleep_for(2000ms);
        RCLCPP_INFO(this->get_logger(), "cb 5");
    }
    

    rclcpp::TimerBase::SharedPtr timer4_;
    rclcpp::TimerBase::SharedPtr timer5_;
    
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node1 = std::make_shared<SingleThreadedExecutorNode>();
    auto node2 = std::make_shared<Node2>();
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node1);
    executor.add_node(node2);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
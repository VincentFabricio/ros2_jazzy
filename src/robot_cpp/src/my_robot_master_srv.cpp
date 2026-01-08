#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/my_robot_srv.hpp"
#include <string>

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;

class MyRobotMasterNode : public rclcpp::Node // MODIFY NAME
{
public:
    MyRobotMasterNode() : Node("master_srv_cpp") // MODIFY NAME
    {
        
        server1 = this->create_service<my_robot_interfaces::srv::MyRobotSrv>(
            "joints_actions", std::bind(&MyRobotMasterNode::srv_callback_actions, this, _1, _2));
        
        timer_actions_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&MyRobotMasterNode::callback_timer_actions_, this));
        set_actions_client = this->create_client<my_robot_interfaces::srv::MyRobotSrv>("joints_actions");
        while (!set_actions_client->wait_for_service(1s))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for Service Server to be up...");
        }
        RCLCPP_INFO(this->get_logger(), "My Robot Server Enable!!");
    }
 
private:

    void callback_timer_actions_()
    {
        if ((j0 == 1) && (j1 == 1) && (diff == 1))
        {
            if ((counter1 == 0))
            {
                callActions("j0on");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "j0on");
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 1) && (action_move == 1))
            {
                callActions("j1on");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "j1on");
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 2) && (action_move == 1))
            {
                callActions("diffon1");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "diffon1");
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 3) && (action_move == 1))
            {
                callActions("diffon2");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 4) && (action_move == 1))
            {
                callActions("diffon3");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 5) && (action_move == 1))
            {
                callActions("diffon4");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 6) && (action_move == 1))
            {
                callActions("diffon5");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 7) && (action_move == 1))
            {
                callActions("diffon6");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 8) && (action_move == 1))
            {
                callActions("diffon7");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            else if ((counter1 == 9) && (action_move == 1))
            {
                callActions("j0on1");
                counter1 ++;
                action_move = 0;
                RCLCPP_INFO(this->get_logger(), "States: %d, %d, %d, %ld, %ld", j0, j1, diff, counter1, action_move);
            }
            
        }
        
        // RCLCPP_INFO(this->get_logger(), "Timer event");
        // callActions("j0ok");
    }
    void srv_callback_actions(
        const std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv::Request> request,
        std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv::Response> response)
    {
        std::string actions = request->actions;
        double pos1 = request->pos1;
        double pos2 = request->pos2;
        double vel1 = request->vel1;
        double vel2 = request->vel2;
        RCLCPP_INFO(this->get_logger(), "Received: %s, %.2f, %.2f, %.2f, %.2f", actions.c_str(), pos1, vel1, pos2, vel2);
        if (((request->actions == "j0ok") || (request->actions == "j0")) && (j0 == 0))
        {
            j0 = 1;
            RCLCPP_INFO(this->get_logger(), "J0OK");
        }
        else if (((request->actions == "j1ok") || (request->actions == "j1")) && (j1 == 0))
        {
            j1 = 1;
            RCLCPP_INFO(this->get_logger(), "J1OK");
        }
        else if (((request->actions == "diffok") || (request->actions == "diff")) && (diff == 0))
        {
            diff = 1;
            RCLCPP_INFO(this->get_logger(), "DIFFOK");
        }

        if ((request->actions == "j0off") || (request->actions == "j1off") || (request->actions == "diffoff1")
             || (request->actions == "diffoff2") || (request->actions == "diffoff3")
             || (request->actions == "diffoff4") || (request->actions == "diffoff5")
             || (request->actions == "diffoff6") || (request->actions == "diffoff7"))
        {
            action_move = 1;
        }
        else if (request->actions == "j0off1")
        {
            action_move = 1;
            counter1 = 0;
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
    void callActions(std::string actions)
    {
        auto request = std::make_shared<my_robot_interfaces::srv::MyRobotSrv::Request>();
        request -> actions = actions;
        
        auto future = set_actions_client->async_send_request(
            request, std::bind(&MyRobotMasterNode::callbackActions, this, _1));
    }
    void callbackActions(rclcpp::Client<my_robot_interfaces::srv::MyRobotSrv>::SharedFuture future)
    {
        auto response = future.get();
        if (response -> success) {
            // RCLCPP_INFO(this->get_logger(), "Server Ok");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Goal accepted by server, waiting for result");
        }
    }

    std::int8_t j0 = 0;
    std::int8_t j1 = 0;
    std::int8_t diff = 0;
    std::int64_t action_move = 1;
    std::int64_t counter1 = 0;

    rclcpp::Service<my_robot_interfaces::srv::MyRobotSrv>::SharedPtr server1;
    my_robot_interfaces::srv::MyRobotSrv actions;
    my_robot_interfaces::srv::MyRobotSrv pos1;
    my_robot_interfaces::srv::MyRobotSrv vel1;
    my_robot_interfaces::srv::MyRobotSrv pos2;
    my_robot_interfaces::srv::MyRobotSrv vel2;
    rclcpp::TimerBase::SharedPtr timer_actions_;
    rclcpp::Client<my_robot_interfaces::srv::MyRobotSrv>::SharedPtr set_actions_client;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyRobotMasterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
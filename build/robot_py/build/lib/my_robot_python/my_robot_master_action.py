#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import MyRobot
 
 
class MyRobotMasterNodeAction(Node):
    def __init__(self):
        super().__init__("my_robot_master_action_py")

        # Server
        self.my_robot_master_server = ActionServer (
            self,
            MyRobot,
            "my_robot",
            goal_callback=self.goal_callback,
            execute_callback=self.execute_callback
        )

 
 
def main(args=None):
    rclpy.init(args=args)
    node = MyRobotMasterNodeAction() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
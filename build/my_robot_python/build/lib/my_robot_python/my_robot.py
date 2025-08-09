#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
 
 
class MyRobotPy(Node):
    def __init__(self):
        super().__init__("my_robot_py") 
        self.counter1 = 0
        self.get_logger().info("Hello World ROS2")
        self.create_timer(1.0, self.timer_callback_)

    def timer_callback_(self):
        self.counter1 += 1
        self.get_logger().info('Timer event' + str(self.counter1))
 
 
def main(args=None):
    rclpy.init(args=args)
    node = MyRobotPy() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
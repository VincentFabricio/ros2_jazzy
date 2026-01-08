#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
import math
 
class MyRobotPy(Node):
    def __init__(self):
        super().__init__("my_robot_py") 

        self.counter1 = 1
        self.joint0 = 0.0
        self.direction = 1.0

        self.get_logger().info("Hello World ROS2")

        self.publisher1 = self.create_publisher(Float64, '/joint0/cmd_pos', 10)
        self.create_timer(1.0, self.timer_callback1)
        # self.publisher2 = self.create_publisher(Float64, '/joint1/cmd_pos', 10)
        # self.create_timer(1.0, self.timer_callback2)

    def timer_callback1(self):
        if self.counter1 == 1 or self.counter1 == 2:
            self.joint0 += self.direction*0.1
        else:
            self.joint0 = 0.0
        
        if self.joint0 >= math.pi/2:
            self.joint0 = math.pi/2
            self.direction = -1
            self.counter1 += 1
        if self.joint0 <= 0.0:
            self.joint0 = 0.0
            self.direction = 1
            self.counter1 += 1

        self.get_logger().info('Timer joint0: ' + str(self.joint0))
        self.get_logger().info('Timer counter: ' + str(self.counter1))
        msg = Float64()
        msg.data = self.joint0
        self.publisher1.publish(msg)

    # def timer_callback2(self):
    #     if self.counter1 == 3 or self.counter1 == 4:
    #         self.joint1 += self.direction*0.1
    #     else:
    #         self.joint1 = 0.0
        
    #     if self.joint1 >= math.pi/2:
    #         self.joint1 = math.pi/2
    #         self.direction = -1
    #         self.counter1 += 1
    #     if self.joint1 <= 0.0:
    #         self.joint1 = 0.0
    #         self.direction = 1
    #         self.counter1 += 1

    #     if self.counter1 == 4:
    #         self.counter1 = 1
        
    #     self.get_logger().info('Timer joint1: ' + str(self.joint1))
    #     self.get_logger().info('Timer counter: ' + str(self.counter1))
    #     msg = Float64()
    #     msg.data = self.joint1
    #     self.publisher2.publish(msg)
 
def main(args=None):
    rclpy.init(args=args)
    node = MyRobotPy() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
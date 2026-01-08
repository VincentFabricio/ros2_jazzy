#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from std_msgs.msg import String
import math
 
class MyRobotPy(Node):
    def __init__(self):
        super().__init__("my_robot_j1_py") 

        self.counter1 = 0
        self.joint0 = 0.0
        self.direction = 1.0
        self.start_j1 = 0

        self.get_logger().info("Joint1")

        self.publisher2 = self.create_publisher(Float64, '/joint1/cmd_pos', 10)
        self.create_timer(0.1, self.timer_callback2)

        self.publisher_actions = self.create_publisher(String, 'actions_joints', 10)
        self.subscriber_joint1 = self.create_subscription(
            String, 'subs_joint1', self.subscriber_callback_joint1, 10)

    def subscriber_callback_joint1(self, msg1):
        self.get_logger().info(msg1.data)

        if msg1.data == "j1y1":
            self.get_logger().info("Comparo")
            self.counter1 += 1
            self.start_j1 = 1
        else:
            self.start_j1 = 0

    def timer_callback2(self):
        if self.counter1 > 0 and self.start_j1 == 1:
            self.joint1 += self.direction*0.1
            self.get_logger().info('Timer joint1: ' + str(self.joint1))
            #self.get_logger().info('Timer counter: ' + str(self.counter1))
        else:
            self.joint1 = 0.01
        
        if self.joint1 >= math.pi/2:
            self.joint1 = math.pi/2
            self.direction = -1
            self.counter1 += 1
        if self.joint1 <= 0.0:
            self.joint1 = 0.0
            self.direction = 1
            self.counter1 += 1

        if self.counter1 == 3:
            self.counter1 = 0
            msg2 = String()
            msg2.data = "j10ff"
            self.publisher_actions.publish(msg2)
        
        msg = Float64()
        msg.data = self.joint1
        self.publisher2.publish(msg)
 
def main(args=None):
    rclpy.init(args=args)
    node = MyRobotPy() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from std_msgs.msg import String
import math
 
class MyRobotPy(Node):
    def __init__(self):
        super().__init__("my_robot_j0_py") 

        self.counter1 = 1
        self.joint0 = 0.0
        self.direction = 1.0

        self.get_logger().info("Joint0")

        self.publisher1 = self.create_publisher(Float64, '/joint0/cmd_pos', 10)
        self.create_timer(1.0, self.timer_callback1)

        self.subscriber_callback_joint0 = self.create_subscription(
            String, 'subs_joint0', self.subscriber_callback_joint0, 10)
        self.publisher_act = self.create_publisher(String, 'actions_joints', 10)
        
    def subscriber_callback_joint0(self, msg3):
        self.get_logger().info(msg3.data)

        if msg3 == "j0y1":
            self.counter1 = 1

    def timer_callback1(self):
        if self.counter1 > 0:
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

        if self.counter1 == 20:
            self.counter1 = 0
            msg5 = String()
            msg5.data = "j0off"
            self.publisher1.publish(msg5)

        self.get_logger().info('Timer joint0: ' + str(self.joint0))
        self.get_logger().info('Timer counter: ' + str(self.counter1))
        msg4 = Float64()
        msg4.data = self.joint0
        self.publisher1.publish(msg4)

 
def main(args=None):
    rclpy.init(args=args)
    node = MyRobotPy() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
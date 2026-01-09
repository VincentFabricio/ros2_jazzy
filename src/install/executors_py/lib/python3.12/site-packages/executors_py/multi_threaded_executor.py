#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup, MutuallyExclusiveCallbackGroup

class NumberPublisherNode(Node):
    def __init__(self):
        super().__init__("multi_threaded_executor_py")
        
        self.cb_group1_ = MutuallyExclusiveCallbackGroup()
        self.cb_group2_ = MutuallyExclusiveCallbackGroup()
        self.cb_group3_ = MutuallyExclusiveCallbackGroup()
        self.cb_group4_ = ReentrantCallbackGroup()
        self.timer1_ = self.create_timer(
            1.0, self.publish_number1, callback_group=self.cb_group1_)
        self.timer2_ = self.create_timer(
            1.0, self.publish_number2, callback_group=self.cb_group2_)
        self.timer3_ = self.create_timer(
            1.0, self.publish_number3, callback_group=self.cb_group3_)
        self.timer4_ = self.create_timer(
            1.0, self.publish_number4, callback_group=self.cb_group3_)
        self.timer5_ = self.create_timer(
            1.0, self.publish_number5, callback_group=self.cb_group4_)
        self.timer6_ = self.create_timer(
            1.0, self.publish_number6, callback_group=self.cb_group4_)
        self.get_logger().info('Started the Multi Threaded Executor')


    def publish_number1(self):
        time.sleep(2.0)
        self.get_logger().info('cb 1')

    def publish_number2(self):
        time.sleep(2.0)
        self.get_logger().info('cb 2')

    def publish_number3(self):
        time.sleep(2.0)
        self.get_logger().info('cb 3')

    def publish_number4(self):
        time.sleep(2.0)
        self.get_logger().info('cb 4')

    def publish_number5(self):
        time.sleep(2.0)
        self.get_logger().info('cb 5')
    
    def publish_number6(self):
        time.sleep(2.0)
        self.get_logger().info('cb 6')

def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    # rclpy.spin(node, MultiThreadeExecutor())
    rclpy.shutdown()


if __name__ == "__main__":
    main()
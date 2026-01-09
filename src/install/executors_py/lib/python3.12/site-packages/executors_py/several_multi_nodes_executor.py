#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup, MutuallyExclusiveCallbackGroup

class Node1(Node):
    def __init__(self):
        super().__init__("several_multi_nodes_executor_py")
        
        self.cb_group1_ = MutuallyExclusiveCallbackGroup()
        self.cb_group2_ = MutuallyExclusiveCallbackGroup()
        
        self.timer1_ = self.create_timer(
            1.0, self.publish_number1, callback_group=self.cb_group1_)
        self.timer2_ = self.create_timer(
            1.0, self.publish_number2, callback_group=self.cb_group2_)
        self.timer3_ = self.create_timer(
            1.0, self.publish_number3, callback_group=self.cb_group2_)
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


class Node2(Node):
    def __init__(self):
        super().__init__("node2")
        self.cb_group3_ = ReentrantCallbackGroup()
        self.timer4_ = self.create_timer(
            1.0, self.publish_number4, self.cb_group3_)
        self.timer5_ = self.create_timer(
            1.0, self.publish_number5, self.cb_group3_)
        self.get_logger().info('Started the second Threaded Executor')

    def publish_number4(self):
        time.sleep(2.0)
        self.get_logger().info('cb 4')

    def publish_number5(self):
        time.sleep(2.0)
        self.get_logger().info('cb 5')


def main(args=None):
    rclpy.init(args=args)
    node1 = Node1()
    node2 = Node2()
    executor = MultiThreadedExecutor()
    executor.add_node(node1)
    executor.add_node(node2)
    executor.spin()
    # rclpy.spin(node, MultiThreadeExecutor())
    rclpy.shutdown()


if __name__ == "__main__":
    main()
#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor

class Node1(Node):
    def __init__(self):
        super().__init__("single_threaded_executor_py")
        
        self.timer1_ = self.create_timer(1.0, self.publish_number1)
        self.timer2_ = self.create_timer(1.0, self.publish_number2)
        self.timer3_ = self.create_timer(1.0, self.publish_number3)
        self.get_logger().info('Started the single Threaded Executor')


    def publish_number1(self):
        time.sleep(2.0)
        self.get_logger().info('cb 1')

    def publish_number2(self):
        time.sleep(2.0)
        self.get_logger().info('cb 2')

    def publish_number3(self):
        time.sleep(2.0)
        self.get_logger().info('cb 3')

def main(args=None):
    rclpy.init(args=args)
    node = Node1()
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    # rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
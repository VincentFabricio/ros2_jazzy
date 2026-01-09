#!/usr/bin/env python3
import time
from rclpy.node import Node

class Node1(Node):
    def __init__(self):
        super().__init__("node1")
        
        self.timer1_ = self.create_timer(1.0, self.publish_number1)
        self.timer2_ = self.create_timer(1.0, self.publish_number2)
        self.timer3_ = self.create_timer(1.0, self.publish_number3)
        self.get_logger().info('Started the firts Threaded Executor')

    def publish_number1(self):
        time.sleep(2.0)
        self.get_logger().info('cb 1')

    def publish_number2(self):
        time.sleep(2.0)
        self.get_logger().info('cb 2')

    def publish_number3(self):
        time.sleep(2.0)
        self.get_logger().info('cb 3')
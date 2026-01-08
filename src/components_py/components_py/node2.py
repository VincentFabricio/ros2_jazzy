#!/usr/bin/env python3
import time
from rclpy.node import Node


class Node2(Node):
    def __init__(self):
        super().__init__("node2")
        
        self.timer4_ = self.create_timer(1.0, self.publish_number4)
        self.timer5_ = self.create_timer(1.0, self.publish_number5)
        self.get_logger().info('Started the second Threaded Executor')

    def publish_number4(self):
        time.sleep(2.0)
        self.get_logger().info('cb 4')

    def publish_number5(self):
        time.sleep(2.0)
        self.get_logger().info('cb 5')
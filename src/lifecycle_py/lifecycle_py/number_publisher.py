#!/usr/bin/env python3
import rclpy
from rclpy.lifecycle import LifecycleNode
from rclpy.lifecycle.node import LifecycleState, TransitionCallbackReturn

from example_interfaces.msg import Int64

class NumerPublisherNode(LifecycleNode):
    def __init__(self):
        super().__init__("number_publisher_py")
        
        self.get_logger().info('In constructor')
        self.number_ = 1
        self.publish_frequency_ = 1.0
        self.number_publisher_ = None
        self.number_timer_ = None

    # Create ROS2 communications, connect to hardware
    def on_configure(self, previous_state: LifecycleState):
        self.get_logger().info('In on_configure')
        self.number_publisher_ = self.create_lifecycle_publisher(Int64, 'number', 10)
        self.number_timer_ = self.create_timer(
            1.0/ self.publish_frequency_, self.publish_number)
        self.number_timer_.cancel()
        # call error
        # raise Exception()
        return TransitionCallbackReturn.SUCCESS
    
    # Activate/Enable Hardware
    def on_activate(self, previous_state: LifecycleState):
        self.get_logger().info('In on_activate')
        self.number_timer_.reset()
        return super().on_activate(previous_state)
    
    # Deactivate/Disable Hardware
    def on_deactivate(self, previous_state: LifecycleState):
        self.get_logger().info('In on_deactivate')
        self.number_timer_.cancel()
        return super().on_deactivate(previous_state)

    # Destroy ROS2 communications, disconnect from Hardware
    def on_cleanup(self, previous_state: LifecycleState):
        self.get_logger().info('In on_cleanup')
        self.destroy_lifecycle_publisher(self.number_publisher_)
        self.destroy_timer(self.number_timer_)
        return TransitionCallbackReturn.SUCCESS
    
    # Shutdown/ Cleanup everything
    def on_shutdown(self, previous_state: LifecycleState):
        self.get_logger().info('In on_shutdown')
        self.destroy_lifecycle_publisher(self.number_publisher_)
        self.destroy_timer(self.number_timer_)
        return TransitionCallbackReturn.SUCCESS
    
    # Process errors, deactivate + cleanup
    def on_error(self, previous_state: LifecycleState):
        self.get_logger().info('In on_error')
        self.destroy_lifecycle_publisher(self.number_publisher_)
        self.destroy_timer(self.number_timer_)
        # do some checks, if ok, then return SUCCESS, if not FAILURE
        return TransitionCallbackReturn.SUCCESS

    def publish_number(self):
        msg = Int64()
        msg.data = self.number_
        self.number_publisher_.publish(msg)
        self.number_ += 1

def main(args=None):
    rclpy.init(args=args)
    node = NumerPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
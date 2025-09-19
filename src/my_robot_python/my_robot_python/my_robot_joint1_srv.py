#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from functools import partial
from std_msgs.msg import Float64
from sensor_msgs.msg import JointState
from my_robot_interfaces.srv import MyRobotSrv

class MyRobotJoint1Node(Node): 
    def __init__(self):
        super().__init__("joint1_srv_py")

        self.direction = 0.0
        self.counter1 = 0
        self.joint1 = 0.0
        self.start_joint1 = 0
        self.msgs_sended = 0
        # Initialize joint variables
        self.joint_pos_map = {}
        self.joint_vel_map = {}
        self.arm1_pos = 0.0
        self.arm1_vel = 0.0
        # PID gains
        self.Kp = 5.0
        self.Ki = 0.50
        self.Kd = 0.01
        self.error = 0.0
        self.d_error = 0.0
        self.integral = 0.0
        self.derivative = 0.0
        self.u_signal = 0.0
        self.set_postion = math.pi/4

        self.publisher1 = self.create_publisher(Float64, '/joint1/cmd_pos', 10)
        self.timer1 = self.create_timer(0.1, self.timer_callback_joint1)
        self.subscriber1 = self.create_subscription(
            JointState, '/joint_states', self.subs_callback_sensors, 10)
        
        self.srv_actions = self.create_service(MyRobotSrv, 'joints_actions', self.callback_srv_actions)
        self.client2_ = self.create_client(MyRobotSrv, 'joints_actions')
        while not self.client2_.wait_for_service(timeout_sec=1.0):
            self.get_logger().error('Interruped while waiting for the server.')

        self.get_logger().info('Joint1 started')
    
    def timer_callback_joint1(self):
        if self.start_joint1 == 0 and self.msgs_sended == 0:
            self.call_srv_client2("j1ok", 0.0, 0.0)
            self.msgs_sended = 1
        
        if self.start_joint1 == 1:
            if self.joint1 <= 0.0:
                self.joint1 = 0.0
                self.direction = 1
                self.counter1 += 1
            elif self.joint1 >= math.pi/2 :
                self.joint1 = math.pi/2
                self.direction = -1
                self.counter1 +=1

            self.joint1 += self.direction * 0.1
            # self.get_logger().info('Joint1: ' + str(self.joint1))
            # self.get_logger().info('Counter: ' + str(self.counter1))
            self.set_postion = self.joint1
            self.error = self.set_postion - self.arm1_pos
            self.integral = self.error * 0.1
            self.derivative = (self.error - self.d_error)/0.1

            self.u_signal = self.Kp * self.error + self.Ki * self.integral + self.Kd * self.derivative
            self.d_error = self.error

            if self.u_signal > math.pi/2:
                self.joint1 = math.pi/2
            elif self.u_signal < 0:
                self.joint1 = 0.0
            else:
                self.joint1 = self.u_signal
        elif self.start_joint1 == 2:
            self.error = self.set_postion - self.arm1_pos
            self.integral = self.error * 0.1
            self.derivative = (self.error - self.d_error)/0.1

            self.u_signal = self.Kp * self.error + self.Ki * self.integral + self.Kd * self.derivative
            self.d_error = self.error

            if self.u_signal > math.pi/2:
                self.joint1 = math.pi/2
            elif self.u_signal < 0:
                self.joint1 = 0.0
            else:
                self.joint1 = self.u_signal
            # self.get_logger().info( "Joint1: " + str(self.joint1))
            # self.get_logger().info( "Error: " + str(self.error))

        elif self.start_joint1 == 0:
            self.joint1 = 0.0

        msg = Float64()
        msg.data = self.joint1
        self.publisher1.publish(msg)

        self.call_srv_client2('j1', self.arm1_pos, self.arm1_vel)

        if self.counter1 == 10:
            self.start_joint1 = 3
            self.counter1 = 0
            self.call_srv_client2("j1off", 0.0, 0.0)


    def subs_callback_sensors(self, msg):
        self.joint_pos_map = dict(zip(msg.name, msg.position))
        self.arm1_pos = self.joint_pos_map.get('second_joint', 0.0)
        self.joint_vel_map = dict(zip(msg.name, msg.velocity))
        self.arm1_vel = self.joint_vel_map.get('second_joint', 0.0)
        # self.get_logger().info( "Sensor1: " + str(self.arm1_pos) + ", " + str(self.arm1_vel))

    def call_srv_client2(self, actions, pos1, vel1):
        self.request = MyRobotSrv.Request()
        self.request.actions = actions
        self.request.pos1 = pos1
        self.request.vel1 = vel1

        self.future = self.client2_.call_async(self.request)
        self.future.add_done_callback(partial(self.callback_client2, actions = actions, pos1 = pos1, vel1 = vel1))

    def callback_client2(self, future, actions, pos1, vel1):
        try:
            response = future.result()
            # self.get_logger().info('Actions: ' + str(actions))
        except Exception as e:
            self.get_logger().error('Service call failed %r' %(e,))
    
    def callback_srv_actions(self, request, response):
        actions = request.actions
        response.success = True
        # self.get_logger().info('Recived: ' + str(actions))
        if request.actions == "j1on":
            self.start_joint1 = 1
        return response
 
def main(args=None):
    rclpy.init(args=args)
    node = MyRobotJoint1Node()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
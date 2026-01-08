#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from functools import partial
from std_msgs.msg import Float64
from sensor_msgs.msg import JointState
from my_robot_interfaces.srv import MyRobotSrv
 
class MyRobotJoint0Node(Node): 
    def __init__(self):
        super().__init__("joint0_srv_py")

        self.counter1 = 0
        self.direction = 0.0
        self.joint0 = 0.0
        self.start_joint0 = 0
        self.msgs_sended = 0
        # Initialize joint variables
        self.joint_pos_map = {}
        self.joint_vel_map = {}
        self.arm1_pos = 0.0
        self.arm1_vel = 0.0
        # PID gains
        self.Kp = 50.0
        self.Ki = 2.0
        self.Kd = 0.1
        self.error = 0.0
        self.d_error = 0.0
        self.integral = 0.0
        self.derivative = 0.0
        self.u_signal = 0.0
        self.set_postion = math.pi/2
        self.state_position = 0

        ## SS with Integral
        self.Kc = 2.69999999999999
        self.K1 = -1.277099999999993
        self.K2 = -0.35899999999999893
        self.x3 = 0.0

        self.publisher1 = self.create_publisher(Float64, '/joint0/cmd_pos', 10)
        self.timer1 = self.create_timer(0.1, self.timer_callback_joint0)
        self.subscriber1 = self.create_subscription(
            JointState, '/joint_states', self.subs_callback_joint0, 10)
        
        self.srv_actions = self.create_service(MyRobotSrv, 'joints_actions', self.callback_srv_actions)
        self.client_ = self.create_client(MyRobotSrv, 'joints_actions')
        while not self.client_.wait_for_service(1):
            self.get_logger().error('Interruped while waiting for the server.')

        self.get_logger().info('Joint0 Start')

    def timer_callback_joint0(self):
        if self.start_joint0 == 0 and self.msgs_sended == 0:
            self.call_srv_client("j0ok", 0.0 , 0.0 )
            self.msgs_sended =1

        
        if self.start_joint0 == 1:
            if self.joint0 <= 0.0:
                self.joint0 = 0.0
                self.direction = 1
                self.counter1 += 1
            elif self.joint0 >= math.pi/2:
                self.joint0 = math.pi/2
                self.direction = -1
                self.counter1 += 1
            self.joint0 += self.direction * 0.2
            # self.get_logger().info('Joint1: ' + str(self.joint1))
            # self.get_logger().info('Counter: ' + str(self.counter1))

            # PID
            # self.set_postion = self.joint1
            # self.error = self.set_postion - self.arm1_pos
            # self.integral = self.error * 0.1
            # self.derivative = (self.error - self.d_error)/0.1

            # self.u_signal = self.Kp * self.error + self.Ki * self.integral + self.Kd * self.derivative
            # self.d_error = self.error

            # SS with integral
            self.set_postion = self.joint0
            self.error = self.set_postion - self.arm1_pos
            self.x3 = self.error * 0.1
            self.u_signal = self.Kc * self.x3 + self.K1*self.arm1_pos + self.K2*self.arm1_vel

            # trigger for the motor
            if self.u_signal > math.pi/2:
                self.joint0 = math.pi/2
            elif self.u_signal < 0:
                self.joint0 = 0.0
            else:
                self.joint0 = self.u_signal
            # print
            # self.get_logger().info( "joint0: " + str(self.joint0))
            # self.get_logger().info( "Error: " + str(self.error))

        elif self.start_joint0 == 2:
            # PID
            # self.error = self.set_postion - self.arm1_pos
            # self.integral = self.error * 0.1
            # self.derivative = (self.error - self.d_error)/0.1

            # self.u_signal = self.Kp * self.error + self.Ki * self.integral + self.Kd * self.derivative
            # self.d_error = self.error
            self.set_postion = math.pi/4
            

            # SS with integral
            self.error = self.set_postion - self.arm1_pos
            self.x3 = self.error * 0.1
            self.u_signal = self.Kc * self.x3 + self.K1*self.arm1_pos + self.K2*self.arm1_vel

            # trigger for the motor
            if self.u_signal > math.pi/2:
                self.joint0 = math.pi/2
            elif self.u_signal < 0:
                self.joint0 = 0.0
            else:
                self.joint0 = self.u_signal
            self.counter1 += 3
            # print
            # self.get_logger().info( "joint0: " + str(self.joint0))
            # self.get_logger().info( "Error: " + str(self.error))

        elif self.start_joint0 == 3:
            # PID
            # self.error = self.set_postion - self.arm1_pos
            # self.integral = self.error * 0.1
            # self.derivative = (self.error - self.d_error)/0.1

            # self.u_signal = self.Kp * self.error + self.Ki * self.integral + self.Kd * self.derivative
            # self.d_error = self.error
            self.set_postion = 0.0
            

            # SS with integral
            self.error = self.set_postion - self.arm1_pos
            self.x3 = self.error * 0.1
            self.u_signal = self.Kc * self.x3 + self.K1*self.arm1_pos + self.K2*self.arm1_vel

            # trigger for the motor
            if self.u_signal > math.pi/2:
                self.joint0 = math.pi/2
            elif self.u_signal < 0:
                self.joint0 = 0.0
            else:
                self.joint0 = self.u_signal
            self.counter1 += 3
            # print
            # self.get_logger().info( "joint0: " + str(self.joint0))
            # self.get_logger().info( "Error: " + str(self.error))

        elif self.start_joint0 == 0:
            self.joint0 = 0.0

        msg = Float64()
        msg.data = self.joint0
        self.publisher1.publish(msg)

        self.call_srv_client('j0', self.arm1_pos, self.arm1_vel)

        if self.counter1 == 10 or self.counter1 == 45:
            self.start_joint0 = 4
            self.counter1 = 0
            self.call_srv_client("j0off", 0.0 , 0.0 )

    def subs_callback_joint0(self, msg):
        self.joint_pos_map = dict(zip(msg.name, msg.position))
        self.arm1_pos = self.joint_pos_map.get('first_joint', 0.0)
        self.joint_vel_map = dict(zip(msg.name, msg.velocity))
        self.arm1_vel = self.joint_vel_map.get('first_joint', 0.0)
        # self.get_logger().info('Sensor0: ' + str(self.arm1_pos) + ', ' + str(self.arm1_vel))

    def call_srv_client(self, actions, pos1, vel1):
        request = MyRobotSrv.Request()
        request.actions = actions
        request.pos1 = pos1
        request.vel1 = vel1

        future = self.client_.call_async(request)
        future.add_done_callback(partial(self.callback_client, actions=actions, pos1 = pos1, vel1 = vel1))

    def callback_client(self, future, actions, pos1, vel1):
        try:
            response = future.result()
            # self.get_logger().info('Action: ' + str(actions))
        except Exception as e:
            self.get_logger().error('Service call failed %r' %(e,))

    def callback_srv_actions(self, request, response):
        actions = request.actions
        response.success =True
        # self.get_logger().info("Recived: " + str(actions))
        if request.actions == "j0on":
            self.start_joint0 = 2
        elif request.actions == "j0on1":
            self.start_joint0 = 3
        return response
        

def main(args=None):
    rclpy.init(args=args)
    node = MyRobotJoint0Node()
    rclpy.spin(node)
    rclpy.shutdown()
 
if __name__ == "__main__":
    main()
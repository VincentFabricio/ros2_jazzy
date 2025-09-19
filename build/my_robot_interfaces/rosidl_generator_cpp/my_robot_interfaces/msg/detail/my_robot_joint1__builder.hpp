// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/MyRobotJoint1.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_joint1.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/my_robot_joint1__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyRobotJoint1_my_robot_joint1
{
public:
  Init_MyRobotJoint1_my_robot_joint1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::MyRobotJoint1 my_robot_joint1(::my_robot_interfaces::msg::MyRobotJoint1::_my_robot_joint1_type arg)
  {
    msg_.my_robot_joint1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::MyRobotJoint1 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::MyRobotJoint1>()
{
  return my_robot_interfaces::msg::builder::Init_MyRobotJoint1_my_robot_joint1();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__BUILDER_HPP_

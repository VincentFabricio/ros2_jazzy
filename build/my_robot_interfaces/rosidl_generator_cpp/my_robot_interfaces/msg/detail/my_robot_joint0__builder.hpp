// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/MyRobotJoint0.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_joint0.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/my_robot_joint0__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyRobotJoint0_my_robot_joint0
{
public:
  Init_MyRobotJoint0_my_robot_joint0()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::MyRobotJoint0 my_robot_joint0(::my_robot_interfaces::msg::MyRobotJoint0::_my_robot_joint0_type arg)
  {
    msg_.my_robot_joint0 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::MyRobotJoint0 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::MyRobotJoint0>()
{
  return my_robot_interfaces::msg::builder::Init_MyRobotJoint0_my_robot_joint0();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/MyRobotDifferential.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_differential.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_DIFFERENTIAL__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_DIFFERENTIAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/my_robot_differential__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyRobotDifferential_differential_robot
{
public:
  Init_MyRobotDifferential_differential_robot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::MyRobotDifferential differential_robot(::my_robot_interfaces::msg::MyRobotDifferential::_differential_robot_type arg)
  {
    msg_.differential_robot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::MyRobotDifferential msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::MyRobotDifferential>()
{
  return my_robot_interfaces::msg::builder::Init_MyRobotDifferential_differential_robot();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_DIFFERENTIAL__BUILDER_HPP_

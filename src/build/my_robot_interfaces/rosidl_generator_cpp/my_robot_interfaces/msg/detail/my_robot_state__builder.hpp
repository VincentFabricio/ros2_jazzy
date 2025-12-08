// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/MyRobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_state.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_STATE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/my_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyRobotState_msg_state
{
public:
  Init_MyRobotState_msg_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::MyRobotState msg_state(::my_robot_interfaces::msg::MyRobotState::_msg_state_type arg)
  {
    msg_.msg_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::MyRobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::MyRobotState>()
{
  return my_robot_interfaces::msg::builder::Init_MyRobotState_msg_state();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_STATE__BUILDER_HPP_

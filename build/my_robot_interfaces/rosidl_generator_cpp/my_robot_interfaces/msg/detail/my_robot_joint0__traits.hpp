// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/MyRobotJoint0.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_joint0.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/my_robot_joint0__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MyRobotJoint0 & msg,
  std::ostream & out)
{
  out << "{";
  // member: my_robot_joint0
  {
    out << "my_robot_joint0: ";
    rosidl_generator_traits::value_to_yaml(msg.my_robot_joint0, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyRobotJoint0 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: my_robot_joint0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_robot_joint0: ";
    rosidl_generator_traits::value_to_yaml(msg.my_robot_joint0, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyRobotJoint0 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::msg::MyRobotJoint0 & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::MyRobotJoint0 & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::MyRobotJoint0>()
{
  return "my_robot_interfaces::msg::MyRobotJoint0";
}

template<>
inline const char * name<my_robot_interfaces::msg::MyRobotJoint0>()
{
  return "my_robot_interfaces/msg/MyRobotJoint0";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::MyRobotJoint0>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::MyRobotJoint0>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::msg::MyRobotJoint0>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__TRAITS_HPP_

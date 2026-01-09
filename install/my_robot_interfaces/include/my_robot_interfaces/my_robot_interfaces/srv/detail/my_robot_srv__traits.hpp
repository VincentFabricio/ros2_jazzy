// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:srv/MyRobotSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/srv/my_robot_srv.hpp"


#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/srv/detail/my_robot_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MyRobotSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: actions
  {
    out << "actions: ";
    rosidl_generator_traits::value_to_yaml(msg.actions, out);
    out << ", ";
  }

  // member: pos1
  {
    out << "pos1: ";
    rosidl_generator_traits::value_to_yaml(msg.pos1, out);
    out << ", ";
  }

  // member: vel1
  {
    out << "vel1: ";
    rosidl_generator_traits::value_to_yaml(msg.vel1, out);
    out << ", ";
  }

  // member: pos2
  {
    out << "pos2: ";
    rosidl_generator_traits::value_to_yaml(msg.pos2, out);
    out << ", ";
  }

  // member: vel2
  {
    out << "vel2: ";
    rosidl_generator_traits::value_to_yaml(msg.vel2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyRobotSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "actions: ";
    rosidl_generator_traits::value_to_yaml(msg.actions, out);
    out << "\n";
  }

  // member: pos1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos1: ";
    rosidl_generator_traits::value_to_yaml(msg.pos1, out);
    out << "\n";
  }

  // member: vel1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel1: ";
    rosidl_generator_traits::value_to_yaml(msg.vel1, out);
    out << "\n";
  }

  // member: pos2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos2: ";
    rosidl_generator_traits::value_to_yaml(msg.pos2, out);
    out << "\n";
  }

  // member: vel2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel2: ";
    rosidl_generator_traits::value_to_yaml(msg.vel2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyRobotSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::srv::MyRobotSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::srv::MyRobotSrv_Request & msg)
{
  return my_robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::srv::MyRobotSrv_Request>()
{
  return "my_robot_interfaces::srv::MyRobotSrv_Request";
}

template<>
inline const char * name<my_robot_interfaces::srv::MyRobotSrv_Request>()
{
  return "my_robot_interfaces/srv/MyRobotSrv_Request";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::MyRobotSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::srv::MyRobotSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MyRobotSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyRobotSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyRobotSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::srv::MyRobotSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::srv::MyRobotSrv_Response & msg)
{
  return my_robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::srv::MyRobotSrv_Response>()
{
  return "my_robot_interfaces::srv::MyRobotSrv_Response";
}

template<>
inline const char * name<my_robot_interfaces::srv::MyRobotSrv_Response>()
{
  return "my_robot_interfaces/srv/MyRobotSrv_Response";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::MyRobotSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::srv::MyRobotSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace my_robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MyRobotSrv_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyRobotSrv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyRobotSrv_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::srv::MyRobotSrv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::srv::MyRobotSrv_Event & msg)
{
  return my_robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::srv::MyRobotSrv_Event>()
{
  return "my_robot_interfaces::srv::MyRobotSrv_Event";
}

template<>
inline const char * name<my_robot_interfaces::srv::MyRobotSrv_Event>()
{
  return "my_robot_interfaces/srv/MyRobotSrv_Event";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::MyRobotSrv_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Event>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Request>::value && has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<my_robot_interfaces::srv::MyRobotSrv_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robot_interfaces::srv::MyRobotSrv>()
{
  return "my_robot_interfaces::srv::MyRobotSrv";
}

template<>
inline const char * name<my_robot_interfaces::srv::MyRobotSrv>()
{
  return "my_robot_interfaces/srv/MyRobotSrv";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::MyRobotSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robot_interfaces::srv::MyRobotSrv_Request>::value &&
    has_fixed_size<my_robot_interfaces::srv::MyRobotSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robot_interfaces::srv::MyRobotSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Request>::value &&
    has_bounded_size<my_robot_interfaces::srv::MyRobotSrv_Response>::value
  >
{
};

template<>
struct is_service<my_robot_interfaces::srv::MyRobotSrv>
  : std::true_type
{
};

template<>
struct is_service_request<my_robot_interfaces::srv::MyRobotSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robot_interfaces::srv::MyRobotSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__TRAITS_HPP_

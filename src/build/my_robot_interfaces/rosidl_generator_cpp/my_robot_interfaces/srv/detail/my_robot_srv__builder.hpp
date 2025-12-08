// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/MyRobotSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/srv/my_robot_srv.hpp"


#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/my_robot_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_MyRobotSrv_Request_vel2
{
public:
  explicit Init_MyRobotSrv_Request_vel2(::my_robot_interfaces::srv::MyRobotSrv_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::MyRobotSrv_Request vel2(::my_robot_interfaces::srv::MyRobotSrv_Request::_vel2_type arg)
  {
    msg_.vel2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Request msg_;
};

class Init_MyRobotSrv_Request_pos2
{
public:
  explicit Init_MyRobotSrv_Request_pos2(::my_robot_interfaces::srv::MyRobotSrv_Request & msg)
  : msg_(msg)
  {}
  Init_MyRobotSrv_Request_vel2 pos2(::my_robot_interfaces::srv::MyRobotSrv_Request::_pos2_type arg)
  {
    msg_.pos2 = std::move(arg);
    return Init_MyRobotSrv_Request_vel2(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Request msg_;
};

class Init_MyRobotSrv_Request_vel1
{
public:
  explicit Init_MyRobotSrv_Request_vel1(::my_robot_interfaces::srv::MyRobotSrv_Request & msg)
  : msg_(msg)
  {}
  Init_MyRobotSrv_Request_pos2 vel1(::my_robot_interfaces::srv::MyRobotSrv_Request::_vel1_type arg)
  {
    msg_.vel1 = std::move(arg);
    return Init_MyRobotSrv_Request_pos2(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Request msg_;
};

class Init_MyRobotSrv_Request_pos1
{
public:
  explicit Init_MyRobotSrv_Request_pos1(::my_robot_interfaces::srv::MyRobotSrv_Request & msg)
  : msg_(msg)
  {}
  Init_MyRobotSrv_Request_vel1 pos1(::my_robot_interfaces::srv::MyRobotSrv_Request::_pos1_type arg)
  {
    msg_.pos1 = std::move(arg);
    return Init_MyRobotSrv_Request_vel1(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Request msg_;
};

class Init_MyRobotSrv_Request_actions
{
public:
  Init_MyRobotSrv_Request_actions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyRobotSrv_Request_pos1 actions(::my_robot_interfaces::srv::MyRobotSrv_Request::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return Init_MyRobotSrv_Request_pos1(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::MyRobotSrv_Request>()
{
  return my_robot_interfaces::srv::builder::Init_MyRobotSrv_Request_actions();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_MyRobotSrv_Response_success
{
public:
  Init_MyRobotSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::srv::MyRobotSrv_Response success(::my_robot_interfaces::srv::MyRobotSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::MyRobotSrv_Response>()
{
  return my_robot_interfaces::srv::builder::Init_MyRobotSrv_Response_success();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_MyRobotSrv_Event_response
{
public:
  explicit Init_MyRobotSrv_Event_response(::my_robot_interfaces::srv::MyRobotSrv_Event & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::MyRobotSrv_Event response(::my_robot_interfaces::srv::MyRobotSrv_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Event msg_;
};

class Init_MyRobotSrv_Event_request
{
public:
  explicit Init_MyRobotSrv_Event_request(::my_robot_interfaces::srv::MyRobotSrv_Event & msg)
  : msg_(msg)
  {}
  Init_MyRobotSrv_Event_response request(::my_robot_interfaces::srv::MyRobotSrv_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MyRobotSrv_Event_response(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Event msg_;
};

class Init_MyRobotSrv_Event_info
{
public:
  Init_MyRobotSrv_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyRobotSrv_Event_request info(::my_robot_interfaces::srv::MyRobotSrv_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MyRobotSrv_Event_request(msg_);
  }

private:
  ::my_robot_interfaces::srv::MyRobotSrv_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::MyRobotSrv_Event>()
{
  return my_robot_interfaces::srv::builder::Init_MyRobotSrv_Event_info();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__BUILDER_HPP_

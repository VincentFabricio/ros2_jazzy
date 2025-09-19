// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:srv/MyRobotSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/srv/my_robot_srv.hpp"


#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Request __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyRobotSrv_Request_
{
  using Type = MyRobotSrv_Request_<ContainerAllocator>;

  explicit MyRobotSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->actions = "";
      this->pos1 = 0.0;
      this->vel1 = 0.0;
      this->pos2 = 0.0;
      this->vel2 = 0.0;
    }
  }

  explicit MyRobotSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : actions(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->actions = "";
      this->pos1 = 0.0;
      this->vel1 = 0.0;
      this->pos2 = 0.0;
      this->vel2 = 0.0;
    }
  }

  // field types and members
  using _actions_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _actions_type actions;
  using _pos1_type =
    double;
  _pos1_type pos1;
  using _vel1_type =
    double;
  _vel1_type vel1;
  using _pos2_type =
    double;
  _pos2_type pos2;
  using _vel2_type =
    double;
  _vel2_type vel2;

  // setters for named parameter idiom
  Type & set__actions(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->actions = _arg;
    return *this;
  }
  Type & set__pos1(
    const double & _arg)
  {
    this->pos1 = _arg;
    return *this;
  }
  Type & set__vel1(
    const double & _arg)
  {
    this->vel1 = _arg;
    return *this;
  }
  Type & set__pos2(
    const double & _arg)
  {
    this->pos2 = _arg;
    return *this;
  }
  Type & set__vel2(
    const double & _arg)
  {
    this->vel2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Request
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Request
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyRobotSrv_Request_ & other) const
  {
    if (this->actions != other.actions) {
      return false;
    }
    if (this->pos1 != other.pos1) {
      return false;
    }
    if (this->vel1 != other.vel1) {
      return false;
    }
    if (this->pos2 != other.pos2) {
      return false;
    }
    if (this->vel2 != other.vel2) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyRobotSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyRobotSrv_Request_

// alias to use template instance with default allocator
using MyRobotSrv_Request =
  my_robot_interfaces::srv::MyRobotSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Response __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyRobotSrv_Response_
{
  using Type = MyRobotSrv_Response_<ContainerAllocator>;

  explicit MyRobotSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MyRobotSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Response
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Response
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyRobotSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyRobotSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyRobotSrv_Response_

// alias to use template instance with default allocator
using MyRobotSrv_Response =
  my_robot_interfaces::srv::MyRobotSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Event __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Event __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyRobotSrv_Event_
{
  using Type = MyRobotSrv_Event_<ContainerAllocator>;

  explicit MyRobotSrv_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit MyRobotSrv_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_robot_interfaces::srv::MyRobotSrv_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_robot_interfaces::srv::MyRobotSrv_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Event
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__MyRobotSrv_Event
    std::shared_ptr<my_robot_interfaces::srv::MyRobotSrv_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyRobotSrv_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyRobotSrv_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyRobotSrv_Event_

// alias to use template instance with default allocator
using MyRobotSrv_Event =
  my_robot_interfaces::srv::MyRobotSrv_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces

namespace my_robot_interfaces
{

namespace srv
{

struct MyRobotSrv
{
  using Request = my_robot_interfaces::srv::MyRobotSrv_Request;
  using Response = my_robot_interfaces::srv::MyRobotSrv_Response;
  using Event = my_robot_interfaces::srv::MyRobotSrv_Event;
};

}  // namespace srv

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__MY_ROBOT_SRV__STRUCT_HPP_

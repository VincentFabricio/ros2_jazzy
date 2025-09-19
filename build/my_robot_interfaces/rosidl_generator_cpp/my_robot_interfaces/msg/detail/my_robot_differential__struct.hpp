// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/MyRobotDifferential.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_differential.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_DIFFERENTIAL__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_DIFFERENTIAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__MyRobotDifferential __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__MyRobotDifferential __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyRobotDifferential_
{
  using Type = MyRobotDifferential_<ContainerAllocator>;

  explicit MyRobotDifferential_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->differential_robot = "";
    }
  }

  explicit MyRobotDifferential_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : differential_robot(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->differential_robot = "";
    }
  }

  // field types and members
  using _differential_robot_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _differential_robot_type differential_robot;

  // setters for named parameter idiom
  Type & set__differential_robot(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->differential_robot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__MyRobotDifferential
    std::shared_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__MyRobotDifferential
    std::shared_ptr<my_robot_interfaces::msg::MyRobotDifferential_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyRobotDifferential_ & other) const
  {
    if (this->differential_robot != other.differential_robot) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyRobotDifferential_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyRobotDifferential_

// alias to use template instance with default allocator
using MyRobotDifferential =
  my_robot_interfaces::msg::MyRobotDifferential_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_DIFFERENTIAL__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/MyRobotJoint0.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_joint0.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__MyRobotJoint0 __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__MyRobotJoint0 __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyRobotJoint0_
{
  using Type = MyRobotJoint0_<ContainerAllocator>;

  explicit MyRobotJoint0_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->my_robot_joint0 = 0.0;
    }
  }

  explicit MyRobotJoint0_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->my_robot_joint0 = 0.0;
    }
  }

  // field types and members
  using _my_robot_joint0_type =
    double;
  _my_robot_joint0_type my_robot_joint0;

  // setters for named parameter idiom
  Type & set__my_robot_joint0(
    const double & _arg)
  {
    this->my_robot_joint0 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__MyRobotJoint0
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__MyRobotJoint0
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint0_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyRobotJoint0_ & other) const
  {
    if (this->my_robot_joint0 != other.my_robot_joint0) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyRobotJoint0_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyRobotJoint0_

// alias to use template instance with default allocator
using MyRobotJoint0 =
  my_robot_interfaces::msg::MyRobotJoint0_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT0__STRUCT_HPP_

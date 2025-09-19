// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/MyRobotJoint1.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_joint1.hpp"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__MyRobotJoint1 __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__MyRobotJoint1 __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyRobotJoint1_
{
  using Type = MyRobotJoint1_<ContainerAllocator>;

  explicit MyRobotJoint1_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->my_robot_joint1 = 0.0;
    }
  }

  explicit MyRobotJoint1_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->my_robot_joint1 = 0.0;
    }
  }

  // field types and members
  using _my_robot_joint1_type =
    double;
  _my_robot_joint1_type my_robot_joint1;

  // setters for named parameter idiom
  Type & set__my_robot_joint1(
    const double & _arg)
  {
    this->my_robot_joint1 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__MyRobotJoint1
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__MyRobotJoint1
    std::shared_ptr<my_robot_interfaces::msg::MyRobotJoint1_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyRobotJoint1_ & other) const
  {
    if (this->my_robot_joint1 != other.my_robot_joint1) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyRobotJoint1_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyRobotJoint1_

// alias to use template instance with default allocator
using MyRobotJoint1 =
  my_robot_interfaces::msg::MyRobotJoint1_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__STRUCT_HPP_

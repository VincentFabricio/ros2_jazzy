// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/MyRobotJoint1.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/my_robot_joint1.h"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/MyRobotJoint1 in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__MyRobotJoint1
{
  double my_robot_joint1;
} my_robot_interfaces__msg__MyRobotJoint1;

// Struct for a sequence of my_robot_interfaces__msg__MyRobotJoint1.
typedef struct my_robot_interfaces__msg__MyRobotJoint1__Sequence
{
  my_robot_interfaces__msg__MyRobotJoint1 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__MyRobotJoint1__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MY_ROBOT_JOINT1__STRUCT_H_

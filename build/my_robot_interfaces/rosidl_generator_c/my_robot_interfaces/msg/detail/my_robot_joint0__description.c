// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_robot_interfaces:msg/MyRobotJoint0.idl
// generated code does not contain a copyright notice

#include "my_robot_interfaces/msg/detail/my_robot_joint0__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__msg__MyRobotJoint0__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe3, 0x9a, 0x77, 0x9f, 0xcc, 0xad, 0x29, 0x8a,
      0x1b, 0xa1, 0xf9, 0x55, 0xc0, 0xd7, 0x7a, 0x7d,
      0xad, 0x0b, 0x5a, 0xdc, 0xab, 0xde, 0x44, 0x52,
      0x26, 0x63, 0x57, 0xfc, 0xe2, 0x26, 0x37, 0x89,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char my_robot_interfaces__msg__MyRobotJoint0__TYPE_NAME[] = "my_robot_interfaces/msg/MyRobotJoint0";

// Define type names, field names, and default values
static char my_robot_interfaces__msg__MyRobotJoint0__FIELD_NAME__my_robot_joint0[] = "my_robot_joint0";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__msg__MyRobotJoint0__FIELDS[] = {
  {
    {my_robot_interfaces__msg__MyRobotJoint0__FIELD_NAME__my_robot_joint0, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__msg__MyRobotJoint0__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__msg__MyRobotJoint0__TYPE_NAME, 37, 37},
      {my_robot_interfaces__msg__MyRobotJoint0__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 my_robot_joint0";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__msg__MyRobotJoint0__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__msg__MyRobotJoint0__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 23, 23},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__msg__MyRobotJoint0__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__msg__MyRobotJoint0__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

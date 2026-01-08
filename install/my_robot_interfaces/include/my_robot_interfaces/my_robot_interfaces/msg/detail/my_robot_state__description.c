// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_robot_interfaces:msg/MyRobotState.idl
// generated code does not contain a copyright notice

#include "my_robot_interfaces/msg/detail/my_robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__msg__MyRobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x25, 0xa1, 0x01, 0xf3, 0xe4, 0x02, 0xb0, 0xbb,
      0x19, 0x4f, 0xbe, 0xb8, 0x70, 0xe7, 0xbd, 0xe0,
      0x02, 0xcb, 0xaa, 0x1f, 0x2c, 0x67, 0x9d, 0x2d,
      0xe2, 0x8e, 0xd9, 0x2f, 0x49, 0x99, 0x1a, 0xdb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char my_robot_interfaces__msg__MyRobotState__TYPE_NAME[] = "my_robot_interfaces/msg/MyRobotState";

// Define type names, field names, and default values
static char my_robot_interfaces__msg__MyRobotState__FIELD_NAME__msg_state[] = "msg_state";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__msg__MyRobotState__FIELDS[] = {
  {
    {my_robot_interfaces__msg__MyRobotState__FIELD_NAME__msg_state, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__msg__MyRobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__msg__MyRobotState__TYPE_NAME, 36, 36},
      {my_robot_interfaces__msg__MyRobotState__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string msg_state";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__msg__MyRobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__msg__MyRobotState__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__msg__MyRobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__msg__MyRobotState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

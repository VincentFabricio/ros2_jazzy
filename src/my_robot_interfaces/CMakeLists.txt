cmake_minimum_required(VERSION 3.5)
project(my_robot_interfaces)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/MyRobotState.msg"
  "msg/MyRobotDifferential.msg"
  "msg/MyRobotJoint0.msg"
  "msg/MyRobotJoint1.msg"
  "msg/LedStateArray.msg"
  "srv/MyRobotSrv.srv"
  "srv/SetLed.srv"
  "action/CountUntil.action"
  "action/MoveRobot.action"
  "action/MoveTurtle.action"
)
ament_export_dependencies(rosidl_default_runtime)

ament_package()
# cmake_minimum_required(VERSION 3.8)
# project(my_robot_interfaces)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rosidl_default_generators REQUIRED)

# rosidl_generate_interfaces(${PROJECT_NAME}
#   "msg/MyRobotState.msg"
#   "msg/MyRobotDifferential.msg"
#   "msg/MyRobotJoint0.msg"
#   "msg/MyRobotJoint1.msg"
#   "srv/MyRobotSrv.srv"
# )
# ament_export_dependencies(rosidl_default_runtime)

# ament_package()

cmake_minimum_required(VERSION 3.8)
project(robot_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(my_robot_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(my_robot_differential_cpp src/my_robot_differential.cpp)
ament_target_dependencies(my_robot_differential_cpp rclcpp geometry_msgs)

add_executable(my_robot_master_cpp src/my_robot_master.cpp)
ament_target_dependencies(my_robot_master_cpp rclcpp geometry_msgs)

add_executable(led_panel_cpp src/led_panel.cpp)
ament_target_dependencies(led_panel_cpp rclcpp my_robot_interfaces)

add_executable(battery_cpp src/led_panel.cpp)
ament_target_dependencies(battery_cpp rclcpp my_robot_interfaces)

add_executable(master_srv_cpp src/my_robot_master_srv.cpp)
ament_target_dependencies(master_srv_cpp rclcpp my_robot_interfaces)

add_executable(differential_node_srv src/my_robot_differential_srv.cpp)
ament_target_dependencies(differential_node_srv rclcpp geometry_msgs my_robot_interfaces sensor_msgs)

install(TARGETS
  my_robot_differential_cpp
  my_robot_master_cpp
  led_panel_cpp
  battery_cpp
  master_srv_cpp
  differential_node_srv
  DESTINATION lib/${PROJECT_NAME}

)

ament_package()

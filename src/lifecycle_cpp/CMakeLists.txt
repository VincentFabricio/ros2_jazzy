cmake_minimum_required(VERSION 3.8)
project(lifecycle_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(my_robot_interfaces REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(number_publisher_cpp src/number_publisher.cpp)
ament_target_dependencies(number_publisher_cpp rclcpp rclcpp_lifecycle example_interfaces)

add_executable(move_robot_lifecycle_server_cpp src/move_robot_lifecycle_server.cpp)
target_include_directories(move_robot_lifecycle_server_cpp PRIVATE include)
ament_target_dependencies(move_robot_lifecycle_server_cpp rclcpp rclcpp_lifecycle rclcpp_action my_robot_interfaces)

install(TARGETS 
  number_publisher_cpp
  move_robot_lifecycle_server_cpp
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

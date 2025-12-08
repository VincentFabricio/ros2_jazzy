cmake_minimum_required(VERSION 3.8)
project(actions_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(my_robot_interfaces REQUIRED)

add_executable(count_until_server_cpp src/count_until_server.cpp)
ament_target_dependencies(count_until_server_cpp rclcpp rclcpp_action my_robot_interfaces)

add_executable(count_until_server_policy1_cpp src/count_until_server_policy_reject.cpp)
ament_target_dependencies(count_until_server_policy1_cpp rclcpp rclcpp_action my_robot_interfaces)

add_executable(count_until_server_policy_queue_cpp src/count_until_server_policy_queue.cpp)
ament_target_dependencies(count_until_server_policy_queue_cpp rclcpp rclcpp_action my_robot_interfaces)

add_executable(count_until_client_cpp src/count_until_client.cpp)
ament_target_dependencies(count_until_client_cpp rclcpp rclcpp_action my_robot_interfaces)


install(TARGETS
  count_until_server_cpp
  count_until_client_cpp
  count_until_server_policy1_cpp
  count_until_server_policy_queue_cpp
  DESTINATION lib/${PROJECT_NAME}/
)
ament_package()

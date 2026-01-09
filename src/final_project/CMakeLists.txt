cmake_minimum_required(VERSION 3.8)
project(final_project)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(my_robot_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)

add_library(turtle_controller_component SHARED src/turtlesim_controller.cpp)
ament_target_dependencies(turtle_controller_component rclcpp rclcpp_components
  rclcpp_action rclcpp_lifecycle turtlesim  geometry_msgs my_robot_interfaces)
rclcpp_components_register_nodes(turtle_controller_component "turtle_controller::TurtleController") 

add_library(turtlebot3_controller_component SHARED src/turtlebot3_controller.cpp)
ament_target_dependencies(turtlebot3_controller_component rclcpp rclcpp_components
  rclcpp_action rclcpp_lifecycle  geometry_msgs my_robot_interfaces)
rclcpp_components_register_nodes(turtlebot3_controller_component "turtlebot3_controller::TurtleBotController") 

add_executable(move_turtle_client_cpp src/move_turtle_client.cpp)
ament_target_dependencies(move_turtle_client_cpp rclcpp rclcpp_action my_robot_interfaces)

add_executable(turtle_controller_cpp src/turtlesim_controller_step3.cpp)
ament_target_dependencies(turtle_controller_cpp rclcpp rclcpp_lifecycle 
  rclcpp_action turtlesim geometry_msgs my_robot_interfaces)

add_executable(turtle_controller_node_cpp src/turtlesim_controller_step1.cpp)
ament_target_dependencies(turtle_controller_node_cpp rclcpp rclcpp_action turtlesim my_robot_interfaces)

add_executable(turtle_controller_action_cpp src/turtlesim_controller_step2.cpp)
ament_target_dependencies(turtle_controller_action_cpp rclcpp rclcpp_action turtlesim geometry_msgs my_robot_interfaces)

install(TARGETS 
  turtle_controller_component
  turtlebot3_controller_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(TARGETS
  turtle_controller_cpp
  turtle_controller_node_cpp
  turtle_controller_action_cpp
  move_turtle_client_cpp
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()

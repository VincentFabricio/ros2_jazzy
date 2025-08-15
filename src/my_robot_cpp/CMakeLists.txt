cmake_minimum_required(VERSION 3.8)
project(my_robot_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(my_robot_differential_cpp src/my_robot_differential.cpp)
ament_target_dependencies(my_robot_differential_cpp rclcpp geometry_msgs)

add_executable(my_robot_master_cpp src/my_robot_master.cpp)
ament_target_dependencies(my_robot_master_cpp rclcpp geometry_msgs)

install(TARGETS
  my_robot_differential_cpp
  my_robot_master_cpp
  DESTINATION lib/${PROJECT_NAME}

)

ament_package()

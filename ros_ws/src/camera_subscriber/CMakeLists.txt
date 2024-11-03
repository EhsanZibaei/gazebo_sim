cmake_minimum_required(VERSION 3.8)
project(camera_subscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
  include
  ${cv_bridge_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(camera_subscriber_node src/camera_subscriber_node.cpp)

ament_target_dependencies(camera_subscriber_node rclcpp sensor_msgs cv_bridge OpenCV)

install(TARGETS
  camera_subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

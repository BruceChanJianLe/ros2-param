#include <rclcpp/rclcpp.hpp>

#include "ros2-param/ros2_param.hpp"

#include <memory>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ros2_param::ROS2Param>();
  rclcpp::spin(node->get_node_base_interface());
  rclcpp::shutdown();

  return EXIT_SUCCESS;
}
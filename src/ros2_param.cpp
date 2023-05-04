#include "ros2-param/ros2_param.hpp"

namespace ros2_param
{
  ROS2Param::ROS2Param()
      : rclcpp_lifecycle::LifecycleNode("ros2_param", rclcpp::NodeOptions().allow_undeclared_parameters(true).automatically_declare_parameters_from_overrides(true))
  {
    ;
  }

  ROS2Param::~ROS2Param() {}

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn ROS2Param::on_configure(const rclcpp_lifecycle::State & /*state*/)
  {
    RCLCPP_INFO(this->get_logger(), "Configuring ROS2 Param Node");

    bool bool_var;
    double double_var;
    std::vector<std::string> string_list;

    this->get_parameter_or("bool_var", bool_var, false);
    this->get_parameter_or("double_var", double_var, 2.0);
    this->get_parameter_or("string_list", string_list, std::vector<std::string>());

    RCLCPP_INFO_STREAM(this->get_logger(), "bool var is " << bool_var);
    RCLCPP_INFO_STREAM(this->get_logger(), "double var is " << double_var);
    RCLCPP_INFO_STREAM(this->get_logger(), "string list size is " << string_list.size());

    std::string string_var;
    int int_var;
    for (const auto &s : string_list)
    {
      RCLCPP_INFO_STREAM(this->get_logger(), "String list elem is " << s);

      this->get_parameter_or(s + ".string_var", string_var, std::string(""));
      this->get_parameter_or(s + ".int_var", int_var, 0);
      RCLCPP_INFO_STREAM(this->get_logger(), "string var is " << string_var);
      RCLCPP_INFO_STREAM(this->get_logger(), "int var is " << int_var);
    }

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn ROS2Param::on_activate(const rclcpp_lifecycle::State & /*state*/)
  {
    RCLCPP_INFO(this->get_logger(), "Activating ROS2 Param Node");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn ROS2Param::on_deactivate(const rclcpp_lifecycle::State & /*state*/)
  {
    RCLCPP_INFO(this->get_logger(), "Deactivating ROS2 Param Node");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn ROS2Param::on_cleanup(const rclcpp_lifecycle::State & /*state*/)
  {
    RCLCPP_INFO(this->get_logger(), "Cleaning up ROS2 Param Node");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn ROS2Param::on_shutdown(const rclcpp_lifecycle::State & /*state*/)
  {
    RCLCPP_INFO(this->get_logger(), "Shutting down ROS2 Param Node");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }
}
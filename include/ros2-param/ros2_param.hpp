#ifndef ROS2_PARAM_ROS2_PARAM_HPP
#define ROS2_PARAM_ROS2_PARAM_HPP

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>

namespace ros2_param
{
  class ROS2Param : public rclcpp_lifecycle::LifecycleNode
  {
  public:
    /**
     * \brief Constructor for the 3D planner server
     *
     */
    ROS2Param();

    /**
     * \brief Destructor for the 3D planner server
     *
     */
    ~ROS2Param();

    /**
     * \brief Configure node
     *
     */
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &state) override;

    /**
     * \brief Activate node
     *
     */
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_activate(const rclcpp_lifecycle::State &state) override;

    /**
     * \brief Deactivate node
     *
     */
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &state) override;

    /**
     * \brief Cleanup node
     *
     */
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_cleanup(const rclcpp_lifecycle::State &state) override;

    /**
     * \brief Shutdown node
     *
     */
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_shutdown(const rclcpp_lifecycle::State &state) override;

  private:
  };
} // namespace ros2_param

#endif /* ROS2_PARAM_ROS2_PARAM_HPP */

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.actions import LifecycleNode

def generate_launch_description():
  ld = LaunchDescription()

  nodes_config = os.path.join(
    get_package_share_directory('ros2-param'),
    'config',
    'params.yaml'
  )
  
  start_node_cmd = LifecycleNode(
    package='ros2-param',
    namespace='main_namespace',
    name='sub_namespace',
    executable='ros2_param_node',
    parameters=[nodes_config],
    output='screen',
    emulate_tty=True
  )

  ld.add_action(start_node_cmd)

  return ld
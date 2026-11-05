import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    blitz_launch = os.path.join(get_package_share_directory('blitz'), 'launch')
    ros_nodes_config = os.path.join(get_package_share_directory('ros_nodes'), 'config')
    nav2_launch = os.path.join(get_package_share_directory('nav2_bringup'), 'launch')

    return LaunchDescription([

        # Publish the static transforms required by slam
        # base_link -> laser (lidar, the lidar is on the dead center of the bot)
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tf_static_pub',
            arguments=['0.0', '0.0', '0.16473', '0.0', '0.0', '0.0', 'base_link', 'laser']
        ),

        # ___________External packages___________

        # Lidar driver package
        Node(
            package='sllidar_ros2',
            executable='sllidar_node',
            name='sllidar_node',
            parameters=[{
                'channel_type': 'serial',
                'serial_port': '/dev/rplidar',
                'serial_baudrate': '115200',
                'frame_id': 'laser',
                'inverted': False,
                'angle_compensate': True
            }],
            output='screen'
        ),

        # slam_toolbox node
        Node(
            package='slam_toolbox',
            executable='async_slam_toolbox_node',
            name='slam_toolbox',
            parameters=[os.path.join(ros_nodes_config, 'slam_toolbox_params.yaml')],
            output='screen'
        ),

        # NAV2
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(nav2_launch, 'navigation_launch.py')),
            launch_arguments= {
                'use_sim_time': 'False',
                'params_file': os.path.join(get_package_share_directory('ros_nodes'), 'config', 'nav2_params.yaml')
            }.items()
        ),

        # ________Our packages_________

        # Odom Node

        # Frontier Detector Node

        # Blitz
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(blitz_launch, 'blitz.launch.py'))
        )
    ])
# Rover Simulation Environment

This project provides a simulation environment for testing a rover connected to a multimodal model. The setup utilizes Gazebo for simulation and ROS 2 for communication.

## Getting Started

### Prerequisites

Make sure you have the following installed:

- Gazebo
- ROS 2 (Jazzy)
- ros_gz_bridge

### Running the Simulation

1. **Launch Gazebo**  
   Start the simulation environment with the following command:
   ```bash
   gz sim building_robot.sdf
   ```

2. **Start the ROS Bridge**  
   Create a bridge between ROS 2 and Gazebo to facilitate communication. Run the command:
   ```bash
   ros2 run ros_gz_bridge parameter_bridge /camera_sensor/image_raw@sensor_msgs/msg/Image@gz.msgs.Image
   ```

3. **Subscribe to Camera Feed**  
   Finally, run the ROS node that subscribes to the camera sensor output:
   ```bash
   ros2 run camera_subscriber camera_subscriber_node
   ```

4. **Visualize the Output**  
   Use a visualization tool to monitor the camera sensor data published to the topic:
   ```bash
   rqt_image_view /camera_sensor/image_raw
   ```

## Contributing

Feel free to fork the repository and submit pull requests for improvements or new features.

## License

This project is licensed under the MIT License.
```

#!/bin/bash

# Set the workspace path
export GZ_WS=$(pwd)/gazebo_models

# Add worlds to Gazebo path
export GZ_SIM_RESOURCE_PATH=$GZ_WS:$GZ_SIM_RESOURCE_PATH

echo "Gazebo workspace configured!"

#!/bin/bash
# Start Xvfb
Xvfb :99 -screen 0 1024x768x24 &
# Wait a moment for Xvfb to start
sleep 1
# Set display variable
export DISPLAY=:99
# Run your program with MLX_HEADLESS through valgrind
export MLX_HEADLESS=1
valgrind --leak-check=full --show-leak-kinds=all --suppressions=mlx.supp ./cub3D 1

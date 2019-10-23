cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h" "base_filter.cpp" "base_filter.h"
    "stb_image.h" "stb_image_write.h" "red_filter.h" "threshold.h" "image_data.h")

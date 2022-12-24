cmake_minimum_required(VERSION 3.5)

project(iic LANGUAGES CXX)

set(TARGET_GEN "camera")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(camera
  main.cpp
)

target_link_libraries(camera PRIVATE libopencv_core.so libopencv_imgproc.so libopencv_imgcodecs.so libopencv_highgui.so libopencv_video.so libopencv_videoio.so)
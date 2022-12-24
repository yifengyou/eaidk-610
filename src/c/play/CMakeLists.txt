cmake_minimum_required(VERSION 3.5)

project(play LANGUAGES CXX)

set(TARGET_GEN "play")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5Core)

add_executable(play
  main.cpp
)

target_link_libraries(play PRIVATE libasound.so)
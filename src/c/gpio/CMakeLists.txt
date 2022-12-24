cmake_minimum_required(VERSION 3.5)

project(iic LANGUAGES CXX)

set(TARGET_GEN "gpio")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gpio
  main.cpp
  gpio_common.cpp
  gpio_common.h
  gpio_case.cpp
  gpio_case.h
)

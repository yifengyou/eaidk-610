cmake_minimum_required(VERSION 3.5)

project(iic LANGUAGES CXX)

set(TARGET_GEN "iic")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(iic
  main.cpp
  iic_common.cpp
  iic_common.h
)

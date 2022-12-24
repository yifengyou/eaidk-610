cmake_minimum_required(VERSION 3.5)

project(rs485 LANGUAGES CXX)

set(TARGET_GEN "rs485")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(rs485
  main.cpp
  rs485_common.cpp
  rs485_common.h
)


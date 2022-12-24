cmake_minimum_required(VERSION 3.5)

project(spi LANGUAGES CXX)

set(TARGET_GEN "spi")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(spi
  main.cpp
  spi_common.cpp
  spi_common.h
)

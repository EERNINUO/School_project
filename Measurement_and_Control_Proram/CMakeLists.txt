cmake_minimum_required(VERSION 3.12)

project(Linear_regression)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

aux_source_directory(./src SRC_LIST)
include_directories(./inc)

add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)
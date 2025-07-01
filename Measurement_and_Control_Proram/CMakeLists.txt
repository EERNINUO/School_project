cmake_minimum_required(VERSION 3.12)

project(Linear_regression
        LANGUAGES CXX
        VERSION 1.0.0
        DESCRIPTION "Linear regression"
        )

set(CMAKE_C_COMPILE_OBJECT "g++")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

AUX_SOURCE_DIRECTORY(./src SRC_LIST)
include_directories(./inc)

add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)
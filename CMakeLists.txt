cmake_minimum_required(VERSION 3.13)

#set the project name and version
project(WaterSim VERSION 0.10)

#specify c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindPkgConfig)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG REQUIRED COMPONENTS SDL3_image-shared)
find_package(SDL3_ttf REQUIRED CONFIG REQUIRED COMPONENTS SDL3_ttf-shared)

add_executable(WaterSim main.cpp)

add_subdirectory(src)
add_subdirectory(include)

target_link_libraries(WaterSim PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)

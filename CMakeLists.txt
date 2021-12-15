cmake_minimum_required(VERSION 3.10)

#set the project name and version
project(WaterSim VERSION 0.4)

#specify c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "include/*.h" "src/*.cpp")
add_executable(WaterSim ${SRC})

target_include_directories(WaterSim PRIVATE include src ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(WaterSim ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

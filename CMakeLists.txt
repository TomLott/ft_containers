cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(containers
      utils.hpp
        queue.hpp
        main.cpp stack.hpp map.hpp map.cpp map.h stack.cpp queue.cpp)
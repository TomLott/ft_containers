cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(containers
       vector.hpp
        list.hpp
      utils.hpp
         main1.cpp)
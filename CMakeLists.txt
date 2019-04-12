cmake_minimum_required(VERSION 3.13)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project2
        main.cpp
        gps.h
        gps.cpp hash_table.cpp hash_table.h _hash_item.cpp)

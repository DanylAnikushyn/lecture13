cmake_minimum_required(VERSION 3.12) 

project(lecture12) 

add_subdirectory(googletest) 

include_directories(googletest/include) 

add_executable(test test.cpp graph.cpp) 

target_link_libraries(test PRIVATE gtest) 
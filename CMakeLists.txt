cmake_minimum_required(VERSION 3.6)
project(midterm_debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Factory.cpp Player.cpp RedRover.cpp Main.cpp doubleLinkedList.h PlayerInterface.h RedRoverInterface.h)
add_executable(midterm ${SOURCE_FILES})
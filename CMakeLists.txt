cmake_minimum_required(VERSION 3.6)
project(u-boot-xlnx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        common/cmd_itest.c)

include_directories(include)

add_executable(u-boot-xlnx ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.16)
project(ReverseKineamticSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(output src/main.cpp src/fk.cpp)

target_include_directories(output PRIVATE include)
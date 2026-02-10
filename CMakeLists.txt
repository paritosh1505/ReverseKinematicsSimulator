cmake_minimum_required(VERSION 3.16)
project(ReverseKineamticSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(rob_op 
        src/main.cpp 
        src/fk.cpp
        src/robot_arm.cpp
        )

target_include_directories(rob_op PRIVATE include)

target_compile_options(rob_op PRIVATE
    -Wall
    -Wextra
    -Werror
    -Wconversion
    -pedantic
    -Wformat=2
    -Wshadow
    -Wnull-dereference
    -g
    -fsanitize=address,undefined
    -fno-omit-frame-pointer
)


target_link_options(rob_op PRIVATE
        -fsanitize=address,undefined        

)       

cmake_minimum_required(VERSION 3.22)
project(CompProg)

set(CMAKE_CXX_STANDARD 14)

add_executable(CompProg
        in_process/crackingthesafe.cpp
        in_process/cubing.cpp
        in_process/oldcrackingthesafe.cpp
        in_process/oldcubing.cpp
        lift.cpp)

add_executable(crackingthesafe in_process/crackingthesafe.cpp)
add_executable(oldcrackingthesafe in_process/oldcrackingthesafe.cpp)
add_executable(sss in_process/sss.cpp)
cmake_minimum_required(VERSION 3.22)

project(CompProg)

set(CMAKE_CXX_STANDARD 14)

add_executable(CompProg
        in_process/bowl_stacking/bowl.cpp
        meh/crackingthesage/crackingthesafe.cpp
        meh/crackingthesage/oldcrackingthesafe.cpp
        meh/cubing/cubing.cpp
        meh/cubing/oldcubing.cpp
        solved/badwiring/wiring.cpp
        solved/colatz/colatz.cpp
        solved/encodedmessage/encodedmesssage.cpp
        solved/lift/lift.cpp
        solved/mosquitos/mosquitos.cpp
        solved/rollingdice/rollingdice.cpp
        solved/venusrover/venusrover.cpp)

add_executable(bowl in_process/bowl_stacking/bowl.cpp)


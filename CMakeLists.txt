cmake_minimum_required(VERSION 3.13)
project(Yahtzee)

set(CMAKE_CXX_STANDARD 14)

include_directories(Yahtzee)

add_executable(Yahtzee
        .idea/encodings.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .idea/Yahtzee.iml
        Yahtzee/cmake-build-debug/cmake_install.cmake
        Yahtzee/cmake-build-debug/CMakeCache.txt
        Yahtzee/cmake-build-debug/Makefile
        Yahtzee/cmake-build-debug/untitled.cbp
        Yahtzee/cmake-build-debug/untitled.exe
        Yahtzee/cmake-build-debug/untitled.ilk
        Yahtzee/cmake-build-debug/untitled.pdb
        Yahtzee/Category.cpp
        Yahtzee/Category.h
        Yahtzee/CMakeLists.txt
        Yahtzee/Dice.cpp
        Yahtzee/Dice.h
        Yahtzee/main.cpp
        Yahtzee/Score.cpp
        Yahtzee/Score.h)

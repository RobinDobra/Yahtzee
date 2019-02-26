cmake_minimum_required(VERSION 3.13)
project(Yahtzee)

set(CMAKE_CXX_STANDARD 14)

include_directories(Yahtzee)

add_executable(Yahtzee
        Yahtzee/Category.cpp
        Yahtzee/Category.h
        Yahtzee/Dice.cpp
        Yahtzee/Dice.h
        Yahtzee/main.cpp
        Yahtzee/Score.cpp
        Yahtzee/Score.h)

cmake_minimum_required(VERSION 3.5)
project(03.homework)
add_executable(03_GUESS_NUMBER 
guess_number.cpp
high_score.cpp
)
set_target_properties(03_GUESS_NUMBER PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
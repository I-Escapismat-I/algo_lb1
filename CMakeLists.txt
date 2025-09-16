cmake_minimum_required(VERSION 3.25)
project(algo_lb1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(algo_lb1 
                src/main.cpp
                src/array_utils.cpp
                src/array_utils.h
                src/matrix_utils.cpp
                src/matrix_utils.h
                src/student_utils.cpp
                src/student_utils.h)


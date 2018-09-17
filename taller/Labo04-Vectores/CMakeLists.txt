cmake_minimum_required(VERSION 3.12)
project(Labo04_Vectores)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Labo04_Vectores
        CMakeLists.txt
        ejercicios.cpp
        ejercicios.h
        main.cpp)

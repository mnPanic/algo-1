
cmake_minimum_required(VERSION 3.6)
project(Labo06)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES
        main.cpp
        src/ej1/esPrimo.cpp
        test/ej1/esPrimoTEST.cpp
        src/ej2/puntaje.cpp
        test/ej2/puntajeTEST.cpp
        src/ej2/llenarTaxis.cpp
        test/ej2/llenarTaxisTEST.cpp)

add_executable(Labo06 ${SOURCE_FILES})

target_link_libraries(Labo06 gtest gtest_main)
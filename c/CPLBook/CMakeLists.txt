cmake_minimum_required(VERSION 3.12)
project(CPLBook)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

##library
add_subdirectory(lib)

##chapter one: A Tutorial Introduction
add_subdirectory(ch1_A_Tutorial_Introduction)

##chapter four: Functions and Program Structure
add_subdirectory(ch4_Functions_and_Program_Structure)

##chapter five: Pointers and Arrays
add_subdirectory(ch5_Pointers_and_Arrays)


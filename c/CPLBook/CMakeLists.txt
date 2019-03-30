cmake_minimum_required(VERSION 3.12)
project(CPLBook)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ch1-6  ch1-6.c)
add_executable(ch1-20 ch1-20.c)
add_executable(ch4-14 ch4-14-macro.c)
add_executable(calc calc/calc.c calc/getop.c calc/getch.c calc/stack.c)

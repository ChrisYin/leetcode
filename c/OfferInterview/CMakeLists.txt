cmake_minimum_required(VERSION 3.12)
project(ForOffer C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(p3_old p3_old.c)
add_executable(p3_new p3_new.c)
add_executable(p4_old p3_2_old.c)
add_executable(p4_new p3_2_new.c)
add_executable(p4_hhh p4_old.c)
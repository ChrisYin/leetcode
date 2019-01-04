cmake_minimum_required(VERSION 3.12)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(p1 p1-TwoSum.cpp )
add_executable(p7 p7-ReverseInteger.cpp)
##array
add_executable(p26 p26-RemoveDuplicatesFromSortedArray.cpp)
add_executable(p905 p905-SortArrayByParity.cpp)
add_executable(p665 p665-NonDecreasingArray.cpp)
##string
add_executable(p13 p13-RomanToInteger.cpp)
add_executable(p345 p345-ReverseVowelsOfAString.cpp)
add_executable(p859 p859-BuddyStrings.cpp)
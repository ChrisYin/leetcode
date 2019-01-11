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
##stack
add_executable(p496 p496-NextGreaterElement.cpp)
add_executable(p225 p225-ImplementStackUsingQueues.cpp)
add_executable(p155 p155-MinStack.cpp)
#dynamic programming
add_executable(p121 p121-BestTimeToBuyAndSellStock.cpp)
add_executable(p53 p53-MaximumSubarray.cpp)
add_executable(p303 p303-RangeSumQuery.cpp)
#math
add_executable(p453 p453-MinimumMovesToEqualArrayElements.cpp)
add_executable(p204 p204-CountPrimes.cpp)
add_executable(p69 p69-sqrtx.cpp)
#tree
add_executable(p617 p617-MergeTwoBinaryTree.cpp)
add_executable(p108 p108-ConvertSortedArrayToBinarySearchTree.cpp)
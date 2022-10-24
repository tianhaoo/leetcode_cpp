cmake_minimum_required(VERSION 3.22)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)

#添加子目录
add_subdirectory(binary_search)
add_subdirectory(binary_tree)
add_subdirectory(classic_problems)
add_subdirectory(company_questions)
add_subdirectory(company_questions_practice)
add_subdirectory(CSAPP)
add_subdirectory(double_pointer)
add_subdirectory(dynamic_programming)
add_subdirectory(graph)
add_subdirectory(greedy)
add_subdirectory(linked_list)
add_subdirectory(others)
add_subdirectory(sliding_window)

add_executable(leetcode_cpp main.cpp)
add_executable(templates templates.cpp)
add_executable(test test.cpp)










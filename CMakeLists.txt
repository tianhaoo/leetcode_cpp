cmake_minimum_required(VERSION 3.22)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)

#添加子目录
add_subdirectory(classic_problems)

add_executable(leetcode_cpp main.cpp)
add_executable(templates templates.cpp)
add_executable(test test.cpp)



# 遍历
add_executable(m1604 others/m1604.cpp)

# 搜索
add_executable(756 others/756.cpp)

# 并查集
add_executable(990 others/990.cpp)
add_executable(261 others/261.cpp)

# 前缀树 字典树

# 单调栈
add_executable(496 others/496.cpp)
add_executable(739 others/739.cpp)

# 单调队列
add_executable(239 others/239.cpp)



# 字符串
add_executable(2278 others/2278.cpp)

# 数组
add_executable(1464 others/1464.cpp)




# 滑动窗口
add_executable(1984 sliding_window/1984.cpp)
add_executable(076 sliding_window/076.cpp)






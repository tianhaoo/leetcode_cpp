cmake_minimum_required(VERSION 3.22)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode_cpp main.cpp)

add_executable(test test.cpp)
add_executable(quicksort quicksort.cpp)
add_executable(mergesort mergesort.cpp)

# 面试题
add_executable(zijie1 zijie1.cpp)
add_executable(haikang1 haikang1.cpp)
add_executable(baidu1 baidu1.cpp)
add_executable(dajiang1 dajiang1.cpp)
add_executable(dajiang2 dajiang2.cpp)
add_executable(dajiang3 dajiang3.cpp)
add_executable(wangyi1 wangyi1.cpp)
add_executable(wangyi2 wangyi2.cpp)
add_executable(wangyi4 wangyi4.cpp)

# 链表
add_executable(002 002.cpp)
add_executable(141 141.cpp)
add_executable(148 148.cpp)

# 回溯
add_executable(017 017.cpp)
add_executable(046 046.cpp)
add_executable(051 051.cpp)

# 动态规划
add_executable(322 322.cpp)

# 二叉树
add_executable(104 104.cpp)
add_executable(543 543.cpp)
add_executable(515 515.cpp)

# 二分查找
add_executable(153 153.cpp)

# 字符串
add_executable(2278 2278.cpp)

# 数组
add_executable(1464 1464.cpp)

# 贪心
add_executable(1221 1221.cpp)

# 双指针
add_executable(344 344.cpp)
add_executable(680 680.cpp)

# 滑动窗口
add_executable(1984 1984.cpp)
add_executable(076 076.cpp)






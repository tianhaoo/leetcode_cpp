//
// Created by Tiana on 2022/8/2.
//


// 选择一个基于头文件名的防护符，这个简单的防护符会确保在一个工程中头文件名总是相互独立的。
// 按照惯例这个防护符是全部大写的。比如Geometry_base.h文件中就应当以如下内容开头：
#ifndef LEETCODE_CPP_UTILS_H
#define LEETCODE_CPP_UTILS_H
#endif //LEETCODE_CPP_UTILS_H

#include<vector>
#include<iostream>
using namespace std;




template<typename T>
void printVector(const vector<T>& list){
    cout << '[';
    for(auto elem: list){
        cout << elem << ", ";
    }
    cout << ']' << endl;
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x);
};


void printLinkedList(ListNode *p);
ListNode* deserializeLinkedList(vector<int> list);

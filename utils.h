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
    ListNode(int x) : val(x), next(nullptr) {};
};


void printLinkedList(ListNode *p){
    while (p){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}


ListNode* deserializeLinkedList(vector<int> list){
    auto head = new ListNode(0);
    auto p = head;
    for (int i=0; i<list.size(); i++) {
        p->next = new ListNode(list[i]);
        p = p->next;
    }
    return head->next;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



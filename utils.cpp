//
// Created by Tiana on 2022/8/2.
//
#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;




//
//template<typename T>
//void printVector(const vector<T>& list){
//    cout << '[';
//    for(auto elem: list){
//        cout << elem << ", ";
//    }
//    cout << ']' << endl;
//}


ListNode::ListNode(int x) : val(x), next(nullptr) {}


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
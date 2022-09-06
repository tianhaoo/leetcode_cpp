// 删除链表中的重复节点

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <random>
#include "../utils.h"

using namespace std;


void remove(ListNode *head){
    ListNode *p1 = head, *p2=p1->next;
    while(p1 != nullptr){
        if(p2 == nullptr){
            return;
        }
        while(p2 != nullptr && p1->val == p2->val){
            p1->next = p2->next;
            p2 = p2->next;
        }
        p1 = p1->next;
        if(p2 == nullptr){
            return;
        }
        p2 = p2->next;
    }

}


int main() {

    auto head = deserializeLinkedList({1, 1, 2, 3, 3});
    printLinkedList(head);
    remove(head);
    printLinkedList(head);


    return 0;
}

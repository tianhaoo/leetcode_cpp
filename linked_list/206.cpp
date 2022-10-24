// 206. 反转链表


#include "../utils.h"


#include <cstdio>
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
#include <list>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto *dummy = new ListNode(0);
        ListNode *p = head;
        while(p != nullptr){
            ListNode *temp = p;
            p = p->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
};


int main() {

    auto head = deserializeLinkedList({1, 2, 3, 4, 5});

    auto solution = Solution();
    auto res = solution.reverseList(head);

    printLinkedList(res);

    return 0;
}

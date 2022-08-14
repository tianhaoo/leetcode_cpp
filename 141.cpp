// 141. 环形链表
// 快慢指针

#include "utils.h"
#include<iostream>
#include <vector>

using namespace std;






class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        auto fast = head;
        auto slow = head;
        while (fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){

    vector<int> list = {3, 2, 0, -4};

    printVector(list);


    auto head = new ListNode(0);
    head->next = deserializeLinkedList(list);

    int pos = 1;
    auto p = head;
    while(p->next)
        p = p->next;
    auto q = head;
    for (int i=0; i<=pos; i++)
        q = q->next;
    p->next = q;


    auto s = Solution();
    cout << s.hasCycle(head->next);

    return 0;
}

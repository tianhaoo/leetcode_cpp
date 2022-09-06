// 82. 删除排序链表中的重复元素 II



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



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        unordered_set<int> s;
        ListNode *p1=head, *p2=p1->next;
        while(p1 != nullptr){
            if(p2 == nullptr){
                break;
            }
            while(p2!=nullptr && p1->val == p2->val){
                s.insert(p2->val);
                p1->next = p2->next;
                p2 = p2->next;
            }
            p1 = p1->next;
            if(p2 == nullptr){
                break;
            }
            p2 = p2->next;
        }
        for(auto item : s){
            cout << item << endl;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while(p->next != nullptr){
            while(s.count(p->next->val)){
                if(p->next->next == nullptr){
                    p->next = nullptr;
                    return dummy->next;
                }
                p->next = p->next->next;
            }
            p = p->next;
        }
        return dummy->next;
    }
};


int main() {
    vector<int> lst = {1,1,1,2,3};
    ListNode *head = deserializeLinkedList({1, 2, 2});
    auto solution = Solution();
    auto res = solution.deleteDuplicates(head);
    printLinkedList(res);
    return 0;
}

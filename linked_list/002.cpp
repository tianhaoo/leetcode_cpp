// 2. 两数相加
// 链表
#include "../utils.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0 && l1->next == nullptr)
            return l2;
        if (l2->val == 0 && l2->next == nullptr)
            return l1;

        ListNode *p1 = l1, *p2 = l2, *dummyHead, *ptr;
        dummyHead = new ListNode(0);
        ptr = dummyHead;
        bool jinwei = false;
        int jinweiValue, tempSum;
        while(p1 != nullptr && p2 != nullptr){
            tempSum = p1->val + p2->val;
            if (jinwei){
                tempSum += jinweiValue;
                jinwei = false;
            }
            if (tempSum >= 10){
                jinwei = true;
                jinweiValue = tempSum / 10;
            }
            ptr->next = new ListNode(tempSum % 10);
            ptr = ptr->next;

            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 != nullptr || p2 != nullptr){
            if (p1 != nullptr && ! jinwei){
                ptr->next = p1;
            }else if (p2 != nullptr && ! jinwei){
                ptr->next = p2;
            }else{ // 存在进位的情况
                // p 指向剩下的那半个链表
                auto p = p1 != nullptr ? p1 : p2;
                ptr->next = p;
                while (p->next != nullptr){
                    if (jinwei){
                        tempSum = p->val + jinweiValue;
                        if (tempSum >= 10){
                            p->val = tempSum % 10;
                            jinweiValue = tempSum / 10;
                            jinwei = true;
                        }else{
                            p->val = tempSum;
                            jinwei = false;
                        }
                    }
                    p = p->next;
                }
                // 此时p指向最后一个节点
                if (jinwei){
                    tempSum = p->val + jinweiValue;
                    if (tempSum >= 10){
                        p->val = tempSum % 10;
                        p->next = new ListNode(tempSum / 10);
                    }else{
                        p->val = tempSum;
                    }
                }
            };
        }else if (jinwei){  // 两个指针都空，但是还有一个进位
            // 先找到尾节点
            auto tail = dummyHead->next;
            while (tail->next != nullptr){
                tail = tail->next;
            }
            tail->next = new ListNode(jinweiValue);
        }
        return dummyHead->next;
    }
};


int main(){
    auto s = Solution();
//    auto p1 = deserializeLinkedList({2, 4, 3});
//    auto p2 = deserializeLinkedList({5, 6, 4});

    auto p1 = deserializeLinkedList({0,8,6,5,6,8,3,5,7});
    auto p2 = deserializeLinkedList({6,7,8,0,8,5,8,9,7});

//    auto p1 = deserializeLinkedList({9,9,9,9,9,9,9});
//    auto p2 = deserializeLinkedList({9,9,9,9});

    auto res = s.addTwoNumbers(p1, p2);
    printVector(serializeLinkedList(res));

    return 0;
}
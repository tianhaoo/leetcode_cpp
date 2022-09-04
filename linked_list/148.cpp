// 148. 链表排序
// 链表归并排序，自顶向下，空间nlogn
#include "../utils.h"
#include <vector>
using namespace std;

class Solution {
public:
    // 给定两个独立链表的头指针，将两个链表合并，返回新链表的头指针
    ListNode* mergeList(ListNode *head1, ListNode *head2){
        ListNode *dummyHead = new ListNode(0);
        ListNode *res=dummyHead, *p1=head1, *p2=head2;
        while (p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                res->next = p1;
                p1 = p1->next;
                res = res->next;
            }else{
                res->next = p2;
                p2 = p2->next;
                res = res->next;
            }
        }
        if(p1 != nullptr){
            res->next = p1;
        }else if (p2 != nullptr){
            res ->next = p2;
        }
        return dummyHead->next;
    }

    // 返回指向中间节点的指针
    ListNode* findMiddle(ListNode *head, ListNode *tail){
        auto fast = head;
        auto slow = head;
        while (fast != tail){
            slow = slow->next;
            fast = fast->next;
            if (fast != tail){
                fast = fast->next;
            }
        }
        return slow;
    }

    // 给定链表的头指针和尾指针，将两个指针范围内的元素排序
    ListNode* sortList(ListNode *head, ListNode *tail) {
        if (head == nullptr)
            return head;
        if (head->next == tail){
            // 只有一个元素，不用排序直接return
            head->next = nullptr;
            return head;
        }
        // 找到中间节点
        auto mid = findMiddle(head, tail);
        // p1 是前一段已排序链表的头指针
        auto p1 = sortList(head, mid);
        // p2 是后一段已排序链表的头指针
        auto p2 = sortList(mid, tail);
        mergeList(p1, p2);
    }
};


int main(){
    auto s = Solution();


    auto p1 = deserializeLinkedList({3,  5, 8, 10});
    auto p2 = deserializeLinkedList({3,  5, 8, 10});

    auto p3 = s.mergeList(p1, p2);
    printVector(serializeLinkedList(p2));

    auto p4 = deserializeLinkedList({3, 2, 1});
    auto sorted = s.sortList(p4, nullptr);
    printVector(serializeLinkedList(sorted));




    return 0;
}
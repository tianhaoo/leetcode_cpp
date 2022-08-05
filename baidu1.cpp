//
// Created by 田浩 on 2022/8/5.
//


#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){

    }

};



void merge(ListNode *low1, ListNode* high1, ListNode* low2, ListNode* high2 ){
    auto *head = new ListNode(0);
    ListNode *p = head;
    auto p1 = low1;
    auto p2 = low2;
    while( p1 != high1 && p2 != high2){
        if (p1->val < p2->val){
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }else{
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }

        // 把剩下的放进末尾
        while(p1 != high1){
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        while(p2 != high2){
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }

        p->next = nullptr;

        p1 = low1;
        p2 = head;
        while (p1 != nullptr && p2!=nullptr && p1!=high2){
            cout << p2->val << endl;
            // p1->val = p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
}


//void mergeSort(ListNode* low, ListNode *high, int size){
//    if (low != high){
//        auto high1 = low;
//        for(int i=0; i<size/2; i++)
//            high1=high1->next;
//        mergeSort(low, high1->next, size/2);
//        mergeSort(high1->next, high->next, size/2);
//
//        merge(low, high1->next, high1->next, high->next);
//
//    }
//
//}

int main(){

    auto head = new ListNode(0);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(5);

    auto p = head->next;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    cout << endl;

    merge(head->next, head->next->next->next, head->next->next->next, head->next->next->next->next->next);
    p = head->next;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    cout << endl;





    return 0;
}
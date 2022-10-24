//
// Created by Tiana on 2022/10/9.
//



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


struct Node{
    int val;
    Node *pre;
    Node *next;
    Node(int v):val(v),pre(nullptr), next(nullptr){};
    Node(int v, Node*p1, Node* p2):val(v), pre(p1), next(p2){};
};

int main() {
    int k;
    while(cin>>k){
        cin.get();

        string input;
        getline(cin, input);

        istringstream ss1(input);

        Node *dummy = new Node(0);
        int temp;
        Node *tail = dummy;
        while(ss1 >> temp){
            auto p = new Node(temp);
            tail->next = p;
            p->pre = tail;

            tail = tail->next;
        }

        if(dummy->next == nullptr){
            continue;
        }

        int count = 0;
        Node *p = dummy;
        while(p != nullptr){
            if(p->val == k){
                auto q = new Node(k);

                auto next = p->next;
                if(next != nullptr){
                    p->next = q;
                    q->next = next;
                    next->pre = q;
                    q->pre = p;

                    p = p->next;
                    if(p->next != nullptr)
                        count ++;

                }else{
                    p->next = q;
                    q->pre = p;

                    p = p->next;

                    if(p->next != nullptr)
                        count ++;
                }
            }
            p = p->next;
        }

        for (int i = 0; i < count; ++i) {
            tail = tail->pre;
            tail->next = nullptr;
        }

        vector<int> lst;
        p = dummy->next;
        while (p!= nullptr){
            lst.push_back(p->val);
            p = p->next;
        }

        for (int i = 0; i < lst.size(); ++i) {
            cout << lst[i];
            if(i+1 < lst.size()){
                cout << ' ';
            }
        }
        cout << endl;



    }

    return 0;
}

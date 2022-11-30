#include"utils.h"

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
#include<thread>
#include<mutex>
#include <unistd.h>

using namespace std;


void search(TreeNode* root, int n, int &ans, int &diff){
    if(root != nullptr){
        int a = root->val;
        int d = abs(a-n);
        if(d <= diff){
            diff = d;
            ans = a;
        }
        cout << a << ", " << n << ", " << d <<endl;
        if(n < a){
            search(root->left, n, ans, diff);
        }else if(n > a){
            search(root->right, n, ans, diff);
        }else{
            ans = a;
            return;
        }
    }
}



struct Node{
    Node *next;
    Node * p;
    Node(): next(nullptr), p(nullptr){};
    Node(Node *p1, Node*p2):next(p1), p(p2){};
};


Node* copy(Node *head1){

    unordered_map<Node*, Node*> map;

    Node * dummy = new Node();
    Node * p2 = dummy;

    Node *p1 = head1;
    while(p1 != nullptr){

        p2->next = new Node();
        p2 = p2->next;

        p1 = p1->next;
    }

    // 顺序拷贝每个Node

    // 如果 p！= nullptr：
      // 如果p指向已经拷贝过的

      // 如果p指向未拷贝过的节点


}


int main() {





    return 0;
}
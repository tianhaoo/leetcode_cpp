//
// Created by Tiana on 2022/8/2.
//


// 选择一个基于头文件名的防护符，这个简单的防护符会确保在一个工程中头文件名总是相互独立的。
// 按照惯例这个防护符是全部大写的。比如Geometry_base.h文件中就应当以如下内容开头：
#ifndef LEETCODE_CPP_UTILS_H
#define LEETCODE_CPP_UTILS_H
#endif //LEETCODE_CPP_UTILS_H

#include <vector>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;



// 输出vector
template<typename T>
void printVector(const vector<T>& lst){
    cout << '[';
    for(int i=0; i<lst.size(); ++i){
        cout << lst[i];
        if (i < lst.size()-1)
            cout << ", ";
    }
    cout << ']' << endl;
}


// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

// 链表转列表
vector<int> serializeLinkedList(ListNode *p){
    vector<int> lst;
    while (p){
        lst.push_back(p->val);
        p = p->next;
    }
    return lst;
}

// 列表转链表
ListNode* deserializeLinkedList(const vector<int>& lst){
    auto dummyHead = new ListNode(0);
    auto p = dummyHead;
    for (int i : lst) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return dummyHead->next;
}

// 输出链表
void printLinkedList(ListNode *p){
    vector<int> lst = serializeLinkedList(p);
    printVector(lst);
}


// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 先序遍历二叉树
void preOrder(TreeNode *root){
    if (root != nullptr){
        cout << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历二叉树
void inOrder(TreeNode *root){
    if (root != nullptr){
        inOrder(root->left);
        cout << root->val << endl;
        inOrder(root->right);
    }
}

// 后序遍历二叉树
void postOrder(TreeNode *root){
    if(root != nullptr){
        postOrder(root->left);
        cout << root->val << endl;
        postOrder(root->right);
    }
}

// 列表转二叉树 leetcode方式
// 节省空间的广度优先搜索
TreeNode* deserializeTree(const vector<int>& lst){
    if (lst.empty()){
        return nullptr;
    }
    auto root = new TreeNode(lst[0]);
    queue<TreeNode *> q;
    q.push(root);

    int index = 1;
    while (! q.empty()){
        auto node = q.front();
        q.pop();

        if (lst[index] != INT_MAX){
            node->left = new TreeNode(lst[index]);
            q.push(node->left);
        }
        index ++;
        if (index >= lst.size()) break;
        if (lst[index] != INT_MAX){
            node->right = new TreeNode(lst[index]);
            q.push(node->right);
        }
        index ++;
        if (index >= lst.size()) break;
    }
    return root;
}


// 二叉树转列表 leetcode方式
// 带null的广度优先遍历
string serializeTree(TreeNode *root){
    vector<int> lst;
    if (root == nullptr){
        return "[]";
    }

    return "[]";


}


// printTree的帮助函数
void writeTree(TreeNode *root, int column){
    if (root != nullptr){
        writeTree(root->right, column+1);
        for (int i=0; i<column; i++){
            cout << "--";
        }
        cout << root->val << endl;
        writeTree(root->left, column+1);
    }
}

// 躺倒打印二叉树， 根在左边，叶子在右边
void printTree(TreeNode *root){
    writeTree(root, 0);
}



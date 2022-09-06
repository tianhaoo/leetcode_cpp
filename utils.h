#ifndef LEETCODE_CPP_UTILS_H
#define LEETCODE_CPP_UTILS_H


#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;




// debug递归函数
#define TIAN 1
#if (TIAN > 0)
#define DECLARE_PRINT \
    int count_ = 0; \
    void printIndent(int n) { \
        for (int i = 0; i < n; i++) { \
            cout << "   "; \
        } \
    }
#define PRINT_PARAM(p1, p2) \
    printIndent(count_++); \
    cout \
    << "p1 = " << p1 << ", " \
    << "p2 = " << p2 << ", " \
    << endl;
#define PRINT_RES(res) \
    printIndent(--count_); \
    cout \
    << "return " << res \
    << endl;
#else
#define  DECLARE_PRINT
#define PRINT_PARAM(p1, p2)
#define PRINT_RES(res)
#endif



class MyTimer{
public:
    DWORD t1,t2;
    MyTimer(){
        t1 = GetTickCount();
    }
    ~MyTimer(){
        t2 = GetTickCount();
        cout <<"time = " << ((t2-t1)*1.0) << " ms" << endl;
    }
};



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

// 输出vector int特化
void printVector(vector<int>& lst){
    cout << '[';
    for(int i=0; i<lst.size(); ++i){
        cout << lst[i];
        if (i < lst.size()-1)
            cout << ", ";
    }
    cout << ']' << endl;
}

// 输出二维数组
template<typename T>
void printMatrix(const vector<vector<T>>& lst){
    cout << '[' << endl;

    for (int i = 0; i < lst.size(); ++i) {
        vector<T> row = lst[i];
        cout << "    [";
        for (int j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j < row.size()-1)
                cout << ", ";
        }
        cout << ']';
        if (i < lst.size()-1)
            cout << ", ";
        cout << endl;
    }
    cout << ']' << endl;
}

// 输出二维数组的int特化
void printMatrix(const vector<vector<int>>& lst){
    cout << '[' << endl;

    for (int i = 0; i < lst.size(); ++i) {
        vector<int> row = lst[i];
        cout << "    [";
        for (int j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j < row.size()-1)
                cout << ", ";
        }
        cout << ']';
        if (i < lst.size()-1)
            cout << ", ";
        cout << endl;
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
TreeNode* deserializeTree(string s){
    // 输入是逗号和空格隔开的int类型字符串
    if (s.empty()){
        return nullptr;
    }
    // 先删除首尾的中括号
    if(s[0] == '[') s.erase(0, 1);
    if(s[s.size()-1] == ']') s.erase(s.size()-1, 1);
    // 然后删除里面的空格
    auto new_end = remove(s.begin(), s.end(), ' ');
    s.erase(new_end, s.end());
    // 然后把逗号换成空格
    replace(s.begin(), s.end(), ',', ' ');
    // 然后把null 换成INT_MAX
    string::size_type pos = 0;
    while ( (pos = s.find("null"))!= string::npos ){
        s.replace(pos, 4, "2147483647");
        ++pos;
    }
    // 最后把int放进vector
    stringstream ss(s);
    vector<int> lst;
    int temp;
    while(ss >> temp){
        lst.push_back(temp);
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
    if (root == nullptr){
        return "[]";
    }
    vector<int> lst;  // 存放结果
    queue<TreeNode*> q;
    q.push(root);
    while(! q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if (node != nullptr){
            lst.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }else{
            lst.push_back(INT_MAX);
        }
    }
    // 为了把后面的null都省略，从后往前找到第一个非INT_MAX的元素下标
    vector<int>::size_type index;
    for(index=lst.size()-1; index>=0; index--){
        if (lst[index] != INT_MAX)
            break;
    }
    string s = "[";
    for (int i=0; i<=index; i++) {
        if (lst[i] == INT_MAX)
            s.append("null");
        else
            s.append(to_string(lst[i]));
        if (i != index)
            s.append(", ");
    }
    s.append("]");
    return s;
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


// 图存储 邻接表
// 图存储 邻接矩阵

// 打印邻接表
void printAdjList(vector<vector<int>> graph){
    int width = 6;
    cout << setiosflags(ios::left) << setw(width) << "from";
    cout << setiosflags(ios::left) << setw(width) << "->";
    cout << setiosflags(ios::left) << setw(width) << "to";
    cout << endl;
    for (int i = 0; i < graph.size(); ++i) {
        const auto lst = graph[i];
        cout << setiosflags(ios::left) << setw(width) << i;
        cout << setiosflags(ios::left) << setw(width) << "->";
        cout << '[';
        for(int j=0; j<lst.size(); ++j){
            cout << lst[j];
            if (j < lst.size()-1)
                cout << ", ";
        }
        cout << ']' << endl;
    }
}



#endif //LEETCODE_CPP_UTILS_H




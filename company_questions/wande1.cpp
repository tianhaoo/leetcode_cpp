// 根据规则计算矩阵乘法次数

// 题目：矩阵计算
// 设计并实现根据用户自定义输入的矩阵数量及矩阵规模行列个数，进行乘法次数计算。
// 注:可根据矩阵乘法特性，使用技巧进行针对性的功能编程
//
// 示例1:
// 矩阵个数：3
// 矩阵A行列个数：20 10
// 矩阵B行列个数：10 15
// 矩阵C行列个数：15 5
// 矩阵相乘规则：((AB)C)
// 输出：
// 乘法次数：4500
//
// 示例2:
// 矩阵个数：2
// 矩阵A行列个数：2 3
// 矩阵B行列个数：3 4
// 矩阵相乘规则：(AB)
// 输出：
// 乘法次数：24







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
#include <sstream>

using namespace std;


struct Node{
    int type; // 0代表左括号，1代表右括号，2代表数字
    int row;
    int col;
    Node(int t, int r, int c):type(t), row(r), col(c){};
};

// 返回两个矩阵相乘所需的乘法次数,和新的Node
pair<Node, int> mutiply(Node &a, Node &b){
    int res = a.row * a.col * b.col;
    return make_pair(Node(2, a.row, b.col), res);
}

bool check(string rule){

    return true;
}

int main() {
    // 输入1：
    // 3
    // 20 10
    // 10 15
    // 15 5
    // ((AB)C)
    // 输出1：
    // 4500

    // 输入2：
    // 2
    // 2 3
    // 3 4
    // (AB)
    // 输出2：
    // 24

    // 输入格式:
    // 全由大写英文字母组成
    // 左右括号要匹配
    // 任意一对括号中间最多为2个元素

    int n; // 矩阵个数
    while(cin >> n){
        vector<int> row(n), col(n);
        for (int i = 0; i < n; ++i) {
            cin >> row[i] >> col[i];
        }
        string rule;  //记录规则
        cin >> rule;

        list<Node> lst;  //将string格式的rule放进链表里
        istringstream ss(rule);
        char temp;
        while(ss >> temp){
            if(temp == '('){
                // 左括号，长宽设为-1
                lst.emplace_back(0, -1, -1);
            }else if(temp == ')'){
                // 右括号，长宽设为-1
                lst.emplace_back(1, -1, -1);
            }else{
                // 假设都是大写英文字母
                lst.emplace_back(2, row[temp-'A'], col[temp-'A']);
            }
        }

        int count = 0;
        stack<list<Node>::iterator> st;
        for (auto p = lst.begin(); p != lst.end(); ++p) {
            if(p->type == 0){
                st.push(p);
            }else if(p->type == 1){
                // 可以假设括号中间有且仅有两个字母
                auto pLeft = st.top();
                auto tempLeft = pLeft;
                st.pop();

                auto pNode1 = ++tempLeft;
                auto pNode2 = ++tempLeft;
                auto pRight = ++tempLeft;
                auto node1 = *pNode1;
                auto node2 = *pNode2;
                auto res = mutiply(node1, node2);

                count += res.second;

                pLeft->type = res.first.type;
                pLeft->row = res.first.row;
                pLeft->col = res.first.col;

                lst.erase(pNode1);
                lst.erase(pNode2);
                lst.erase(pRight);
                p = pLeft;

            }else{
                continue;
            }
        }
        cout << count << endl;
    }

    return 0;
}


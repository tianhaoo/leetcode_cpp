// 矩阵链乘
// 动态规划
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

// 返回两个矩阵相乘所需的乘法次数
int mutiply(int row1, int col1, int row2, int col2){
    if(col1 != row2){
        // 无法相乘
        return -1;
    }
    return col1;
}

// 返回从第i个矩阵乘到第j个矩阵的最小乘法次数
int dp(vector<int> &row, vector<int> &col, int i, int j){
    if(i==j){
        // 一个矩阵，代表已经得出结果，不用乘
        return 0;
    }

    // k代表在第k个元素后面插入分割点, 将i和j分成两部分
    for (int k = i; k < j; ++k) {
        int left = dp(row, col, i, k);
        int right = dp(row, col, k+1, j);
        return left + right + row[i]*col[k]*col[j];
    }
}


int main() {
    
    int a = 1;
    char b = 0x80;
    char x = a & b;
    printf("%x\n", x);

    
    
    

    int n; // 矩阵个数
    while(cin >> n){
        vector<int> row(n), col(n);
        for (int i = 0; i < n; ++i) {
            cin >> row[i] >> col[i];
        }
    }

    return 0;
}

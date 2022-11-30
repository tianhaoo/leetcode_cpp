// 矩阵链乘
// 动态规划

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


// 返回从第i个矩阵乘到第j个矩阵的最小乘法次数
int dp(vector<int> &row, vector<int> &col, int i, int j){
    if(i==j){
        // 一个矩阵，代表已经得出结果，不用乘
        return 0;
    }
    // k代表在第k个元素后面插入分割点, 将i和j分成两部分
    int res = INT_MAX;
    for (int k = i; k < j; ++k) {
        int left = dp(row, col, i, k);
        int right = dp(row, col, k+1, j);
        int temp = left + right + row[i]*col[k]*col[j];
        res = min(res, temp);
    }
    return res;
}



int main() {
    int n; // 矩阵个数
    while(cin >> n){
        vector<int> row(n), col(n);
        for (int i = 0; i < n; ++i) {
            cin >> row[i] >> col[i];
        }
        string rule;
        cin >> rule;


    }

    return 0;
}
//
// Created by Tiana on 2022/9/20.
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
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


int dp(vector<vector<int>> &memo, string word1, int i, string word2, int j){
    if (i==-1) return j+1;
    if (j == -1) return i+1;
    if(memo[i][j] != -1) return memo[i][j];

    if(word1[i] == word2[j]){
        return dp(memo, word1, i-1, word2, j-1);
    }
    // 在i的位置插入一个元素
    int p1 = dp(memo, word1, i, word2, j-1) + 1;
    // 删除i位置的元素
    int p2 = dp(memo, word1, i-1, word2, j) + 1;
    // 改动i位置的元素
    int p3 = dp(memo, word1, i-1, word2, j-1) + 1;
    int res = min(min(p1, p2), p3);
    memo[i][j] = res;
    return res;
}

int minDistance(string word1, string word2) {
    // word1 -> word2

    vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
    return dp(memo, word1, word1.size()-1, word2, word2.size()-1);

}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    auto res = minDistance(word1, word2);
    cout << res << endl;

    return 0;
}


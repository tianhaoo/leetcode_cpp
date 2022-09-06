// 174. 地下城游戏



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
#include <random>
#include "../utils.h"

using namespace std;

DECLARE_PRINT

// 返回
// 从i，j出发，能安全到达右下角所需的最小生命值
int dp(vector<vector<int>> &dungeon, int n, int m, int i, int j, vector<vector<int>> &memo){
    if(i == n-1 && j == m-1){
        int res=1;
        if(dungeon[i][j] < 0){
            res -= dungeon[i][j];
        }
        return res;
    }
    if(memo[i][j] != INT_MIN){
        return memo[i][j];
    }

    // 往右走
    int p1=INT_MAX;
    if(j+1 <= m-1){
        p1 = dp(dungeon, n, m, i, j+1, memo) - dungeon[i][j];
        p1 = p1 <= 0? 1: p1;
    }
    // 往下走
    int p2=INT_MAX;
    if(i+1 <= n-1){
        p2 = dp(dungeon, n, m, i+1, j, memo) - dungeon[i][j];
        p2 = p2 <= 0? 1: p2;
    }
    int res = min(p1, p2);
    memo[i][j] = res;
    return res;
}

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> memo(n, vector<int>(m, INT_MIN));
        int res = dp(dungeon, n, m, 0, 0, memo);
        return res;
    }
};


int main() {
    vector<vector<int>> dungeon={
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}
    };
    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.calculateMinimumHP(dungeon);
    cout << res << endl;

    return 0;
}

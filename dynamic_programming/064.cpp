// 64. 最小路径和
// 动态规划



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

// 从0，0走到i，j的最小路径和
int dp(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &memo){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(memo[i][j] != INT_MIN){
        return memo[i][j];
    }
    // 从上面的格子过来的
    int p1 = INT_MAX;
    if(i-1>=0){
        p1 = grid[i][j] + dp(grid, i-1, j, memo);
    }
    // 从左边的格子过来的
    int p2 = INT_MAX;
    if(j-1>=0){
        p2 = grid[i][j] + dp(grid, i, j-1, memo);
    }
    int res = min(p1, p2);
    memo[i][j] = res;
    return res;
}



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, INT_MIN));
        int res = dp(grid, m-1, n-1, memo);
        return res;
    }
};


int main() {

    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.minPathSum(grid);
    cout << res << endl;


    return 0;
}

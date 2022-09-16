// 1020. 飞地的数量



#include "../utils.h"


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


class Solution {
public:
    vector<vector<int>> directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };

    void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<bool>> &visited, int &count){
        if(visited[i][j] || grid[i][j] == 0){
            return;
        }
        visited[i][j] = true;
        count ++;
        for(auto d : directions){
            int nextI = i+d[0];
            int nextJ = j+d[1];
            if(nextI >=0 && nextI < m && nextJ >=0 && nextJ < n && !visited[nextI][nextJ] && grid[nextI][nextJ] == 1){
                dfs(grid, nextI, nextJ, m, n, visited, count);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; ++i){
            if(!visited[i][0]  && grid[i][0] == 1){
                dfs(grid, i, 0, m, n, visited, count);
            }
            if(!visited[i][n-1] && grid[i][n-1] == 1){
                dfs(grid, i, n-1, m, n, visited, count);
            }
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(grid, 0, i, m, n, visited, count);
            }
            if(!visited[m-1][i] && grid[m-1][i] == 1){
                dfs(grid, m-1, i, m, n, visited, count);
            }
        }

        int sum = 0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(!visited[i][j]  && grid[i][j] == 1){
                    count = 0;
                    dfs(grid, i, j, m, n, visited, count);
                    sum += count;
                }
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> grid = {{0,0,0,1,1,1,0,1,1,1,1,1,0,0,0},{1,1,1,1,0,0,0,1,1,0,0,0,1,1,1},{1,1,1,0,0,1,0,1,1,1,0,0,0,1,1},{1,1,0,1,0,1,1,0,0,0,1,1,0,1,0},{1,1,1,1,0,0,0,1,1,1,0,0,0,1,1},{1,0,1,1,0,0,1,1,1,1,1,1,0,0,0},{0,1,0,0,1,1,1,1,0,0,1,1,1,0,0},{0,0,1,0,0,0,0,1,1,0,0,1,0,0,0},{1,0,1,0,0,1,0,0,0,0,0,0,1,0,1},{1,1,1,0,1,0,1,0,1,1,1,0,0,1,0}};

    printMatrix(grid);

    auto solution = Solution();
    auto res = solution.numEnclaves(grid);
    cout << res << endl;

    return 0;
}

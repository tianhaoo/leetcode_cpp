// 130. 被围绕的区域
// 图
// dfs 并查集


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;




// dfs 解法
class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, vector<vector<int>> &directions, int m, int n, int i, int j){
        if (visited[i][j]) return;
        visited[i][j] = true;
        for (const auto &direction: directions) {
            int next_i = i + direction[0], next_j = j + direction[1];
            if(next_i >= 0 && next_i <= m-1 && next_j >=0 && next_j <= n-1 && board[next_i][next_j] == 'O'){
                dfs(board, visited, directions, m, n, next_i, next_j);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()){
            return;
        }

        int m=(int)board.size(), n=(int)board[0].size();
        vector<vector<int>> directions = {
                {0, 1},
                {1, 0},
                {0, -1},
                {-1, 0}
        };

        // 先在棋盘边缘寻找搜索起点
        vector<vector<int>> starts;
        // 搜索每一行
        for (int i = 0; i < m; ++i) {
            if(board[i][0] == 'O'){
                starts.push_back({i, 0});
            }
            if(board[i][n-1] == 'O'){
                starts.push_back({i, n-1});
            }
        }
        // 搜索每一列
        for (int j = 0; j < n; ++j) {
            if(board[0][j] == 'O'){
                starts.push_back({0, j});
            }
            if(board[m-1][j] == 'O'){
                starts.push_back({m-1, j});
            }
        }

        // 从每个起点开始遍历
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (const auto &start: starts) {
            int i = start[0], j= start[1];
            if(!visited[i][j]){
                dfs(board, visited, directions, m, n, i, j);
            }
        }


        // 如果没有visit过，就置为X
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};










// class UF{
// public:
//     int count;
//     vector<int> parent;
//     UF(int n){
//         count = n;
//         parent.resize(n);
//         for (int i = 0; i < n; ++i) {
//             parent[i] = i;
//         }
//     }
//     void union_(int p, int q){
//         int rootP = find(p);
//         int rootQ = find(q);
//         if (rootP == rootQ){
//             return;
//         }else{
//             parent[rootQ] = rootP;
//             count --;
//         }
//     }
//
//     int find(int x){
//         if(parent[x] != x){
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
//     bool connected(int p, int q){
//         return find(p) == find(q);
//     }
// };
//
// // 并查集解法
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         if (board.empty()){
//             return;
//         }
//
//         int m=(int)board.size(), n=(int)board[0].size(), dummy =m*n;
//         UF uf(m*n + 1);
//         // 从上往下扫描，第0列和第n-1列
//         for (int i = 0; i < m; ++i) {
//             if(board[i][0] == 'O'){
//                 uf.union_(dummy, i*n+0);
//             }
//             if(board[i][n-1] == 'O'){
//                 uf.union_(dummy, i*n + n-1);
//             }
//         }
//
//         // 从左往右扫描，第0行和第m-1行
//         for (int i = 0; i < n; ++i) {
//             if(board[0][i] == 'O'){
//                 uf.union_(dummy, 0*n+i);
//             }
//             if(board[m-1][i] == 'O'){
//                 uf.union_(dummy, (m-1)*n+i);
//             }
//         }
//
//         // 将棋盘内所有的O都和上下左右的O连通
//         vector<vector<int>> directions = {
//                 {0, 1},
//                 {1, 0},
//                 {0, -1},
//                 {-1, 0}
//         };
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if(board[i][j] == 'O'){
//                     for (const auto &direction: directions) {
//                         int next_i = i+direction[0], next_j = j+direction[1];
//                         if(next_i >= 0 && next_i <= m-1 && next_j >= 0 && next_j <= n-1 && board[next_i][next_j] == 'O'){
//                             uf.union_(i*n+j, next_i*n+next_j);
//                         }
//                     }
//                 }
//             }
//         }
//
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if(! uf.connected(dummy, i*n+j)){
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };



int main() {

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    // vector<vector<char>> board = {{'X','O','X'},{'X','O','X'},{'X','O','X'}};
    // vector<vector<char>> board = {{'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'}};
    printMatrix<char>(board);

    auto solution = Solution();
    solution.solve(board);
    printMatrix<char>(board);


    return 0;
}

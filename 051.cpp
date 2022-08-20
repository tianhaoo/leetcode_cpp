// 51. N 皇后
// 回溯


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;


class Solution {

public:
    bool valid(const vector<string> & board, const int row, const int col){

        for (int i = 0; i < board.size(); ++i) {
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        int current_row, current_col;
        current_row = row;
        current_col = col;
        while( current_row >= 0 && current_row <= board.size()-1 && current_col >= 0 && current_col <= board.size()-1 ){
            // 往左上查找
            if(board[current_row][current_col] == 'Q'){
                return false;
            }
            current_row --;
            current_col --;
        }
        current_row = row;
        current_col = col;
        while( current_row >= 0 && current_row <= board.size()-1 && current_col >= 0 && current_col <= board.size()-1 ){
            // 往右上查找
            if(board[current_row][current_col] == 'Q'){
                return false;
            }
            current_row --;
            current_col ++;
        }
        return true;
    }


    void backtrack(vector<vector<string>> &res, vector<string>& board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size() ; ++col) {
            if(! valid(board, row, col)){
                continue;
            }
            board[row][col] = 'Q';
            backtrack(res, board, row+1);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);

        return res;
    }
};


int main() {

    int n = 4;
    auto solution = Solution();
    auto res = solution.solveNQueens(n);
    for (auto &lst: res) {
        printVector<string>(lst);
    }

    return 0;
}

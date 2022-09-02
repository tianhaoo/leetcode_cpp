// 面试题 16.04. 井字游戏

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;





class Solution {
public:


    string tictactoe(vector<string>& board) {
        int n = board.size();
        int ii, jj;
        char c;
        string win;
        bool ok=false;
        bool hasEmpty=false;

        int xCount;
        int oCount;
        int eCount;

        // 先检测中间的左上到右下
        ii=0; jj=0;
        xCount=0;
        oCount=0;
        eCount=0;
        while(ii<n && jj<n){
            c = board[ii][jj];
            if(c == 'X'){
                xCount++;
            }
            if(c == 'O'){
                oCount++;
            }
            if(c == ' '){
                eCount++;
            }
            ++ii;
            ++jj;
        }
        if(xCount==n){
            ok=true;
            win = "X";
        }
        if(oCount==n){
            ok=true;
            win = "O";
        }
        if(eCount > 0){
            hasEmpty = true;
        }

        // 然后是右上到左下
        ii=n-1; jj=0;
        xCount=0;
        oCount=0;
        eCount=0;
        while(ii >=0 && jj<n){
            c = board[ii][jj];
            if(c == 'X'){
                xCount++;
            }
            if(c == 'O'){
                oCount++;
            }
            if(c == ' '){
                eCount++;
            }
            --ii;
            ++jj;
        }
        if(xCount==n){
            ok=true;
            win = "X";
        }
        if(oCount==n){
            ok=true;
            win = "O";
        }
        if(eCount > 0){
            hasEmpty = true;
        }
        // 检查每一行
        for(ii=0; ii<n; ++ii){
            xCount=0;
            oCount=0;
            eCount=0;
            for(jj=0; jj<n; ++jj){
                c = board[ii][jj];
                if(c == 'X'){
                    xCount++;
                }
                if(c == 'O'){
                    oCount++;
                }
                if(c == ' '){
                    eCount++;
                }
            }
            if(xCount==n){
                ok=true;
                win = "X";
            }
            if(oCount==n){
                ok=true;
                win = "O";
            }
            if(eCount > 0){
                hasEmpty = true;
            }
        }
        // 检查每一列
        for(jj=0; jj<n; ++jj){
            xCount=0;
            oCount=0;
            eCount=0;
            for(ii=0; ii<n; ++ii){
                c = board[ii][jj];
                if(c == 'X'){
                    xCount++;
                }
                if(c == 'O'){
                    oCount++;
                }
                if(c == ' '){
                    eCount++;
                }
            }
            if(xCount==n){
                ok=true;
                win = "X";
            }
            if(oCount==n){
                ok=true;
                win = "O";
            }
            if(eCount > 0){
                hasEmpty = true;
            }
        }
        if(ok){
            return win;
        }else{
            return hasEmpty ? "Pending" : "Draw";
        }
    }
};


int main() {

    // vector<string> board = {"O X"," XO","X O"};
    // vector<string> board = {"OOX","XXO","OXO"};
    vector<string> board = {"OOX","XXO","OX "};
    // vector<string> board = {"OX ","OX ","O  "};
    auto solution = Solution();
    auto res = solution.tictactoe(board);
    cout << res << endl;

    return 0;
}

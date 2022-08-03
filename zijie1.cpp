//
// Created by Tiana on 2022/8/2.
//


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int m, int n){
    if

}


int main() {
    // 求最大连通域面积
    int m = 6;
    int n = 6;
    vector<vector<int>> matrix = {
            {1, 1, 1, 0, 0, 0},
            {1, 1, 1, 0, 0, 0},
            {1, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 1, 1},
            {1, 1, 1, 0, 0, 0},
            {1, 1, 1, 0, 0, 0},
    };
    for (auto list : matrix){
        for (auto n : list){
            cout << n << ' ';
        }
        cout << endl;
    }


    vector<vector<bool>> visited(m, vector<bool>(n, false));





}



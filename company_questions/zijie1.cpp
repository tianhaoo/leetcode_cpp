//
// Created by Tiana on 2022/8/2.
//


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


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

vector<vector<bool>> visited(m, vector<bool>(n, false));

vector<vector<int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};

int maxValue = -0x3f3f3f3f;



void dfs(int i, int j, int &count){
    if (visited[i][j]) return;
    if (matrix[i][j] == 0) return;
    visited[i][j] = true;
    count ++;
    for (auto direction : directions){
        int next_i = i + direction[0];
        int next_j = j + direction[1];
        if ( next_i >= 0 && next_i <= m-1 && next_j >= 0 && next_j <= n-1){
            dfs(next_i, next_j, count);
        }
    }
}


int main() {
    // 求最大连通域面积

    for (auto list : matrix){
        for (auto n : list){
            cout << n << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for (auto list : visited){
        for (auto n : list){
            cout << n << ' ';
        }
        cout << endl;
    }

    cout << endl;

    int count;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            count = 0;
            dfs(i, j, count);
            cout << count << endl;
            maxValue = max(maxValue, count);
        }
    }
    cout << "@" << maxValue << endl;



    cout << endl;
    for (auto list : matrix){
        for (auto n : list){
            cout << n << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for (auto list : visited){
        for (auto n : list){
            cout << n << ' ';
        }
        cout << endl;
    }







}



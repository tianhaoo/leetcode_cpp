//
// Created by peiwen on 2022/8/7.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//  6 6 2 3 3
//  37 37 39 41 13 205
//  37 41 41 203 39 243
//  37 41 40 131 40 41
//  91 41 39 198 41 9
//  189 41 39 40 40 38
//  37 124 38 167 41 41


struct node{
    int x;
    int y;
    node(int a, int b){
        x = a;
        y = b;
    }
};

vector<vector<int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};

int N, M, X, Y, T;
int count;



void bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
    queue<node> q;
    q.push(node(X, Y));
    visited[X][Y] = true;
    count ++;
    while (!q.empty()) {
        size_t sz = q.size();
        for (int i = 0; i < sz; i++) {
            node n = q.front();
            q.pop();
            for (auto direction: directions) {
                int next_i = n.x + direction[0];
                int next_j = n.y + direction[1];
                if (next_i >= 0 && next_i <= N - 1 && next_j >= 0 && next_j <= M - 1 && !visited[next_i][next_j]) {
                    q.push(node(next_i, next_j));
                    visited[next_i][next_j] = true;
                    if(abs(matrix[next_i][next_j] - matrix[next_i][next_j]) < T)
                        count ++;
                }
            }
        }

    }
}

int main(){

    int temp;
    while (cin >> N >> M >> X >> Y >> T){
        vector<vector<int>> matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> temp;
                matrix[i][j] = temp;
            }
        }

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        count = 0;
        bfs(matrix, visited);
        cout << count << endl;




    }

    return 0;
}
// 网易游戏雷火 第一题
#include<iostream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<vector<int>> &directions, int n, int m, int i, int j){
    if (visited[i][j]) return;
    if (matrix[i][j] == 0) return;
    visited[i][j] = true;
    for (auto direction : directions){
        int next_i = i + direction[0];
        int next_j = j + direction[1];
        if ( next_i >= 0 && next_i <= n-1 && next_j >= 0 && next_j <= m-1){
            dfs(matrix, visited, directions, n, m, next_i, next_j);
        }
    }
}

int main(){
    int n, m, p, q;
    while(cin >> n >> m){
        vector<vector<int>> matrix(n, vector<int>(m, 1)); // 1代表通的, 0代表不通
        cin >> p;
        int a, b;
        string temp;
        for(int i=0; i<p; i++){
            cin >> temp;
            auto pos = temp.find(',');
            a = stoi(temp.substr(0, pos));
            b = stoi(temp.substr(pos+1, temp.size()-pos-1));
            matrix[a][b] = 0;
        }
        cin >> q;
        vector<int> lst1, lst2;
        for(int i=0; i<q; i++){
            cin >> temp;
            auto pos = temp.find(',');
            a = stoi(temp.substr(0, pos));
            b = stoi(temp.substr(pos+1, temp.size()-pos-1));
            lst1.push_back(a);
            lst2.push_back(b);
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> directions = {
                {0, 1},
                {1, 0},
                {0, -1},
                {-1, 0},
                {1, 1},
                {1, -1},
                {-1, 1},
                {-1, -1}
        };




//    for (auto list : matrix){
//        for (auto n : list){
//            cout << n;
//        }
//        cout << endl;
//    }
//    cout << endl;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (!visited[i][j]){
                    dfs(matrix, visited, directions, n, m, 0, 0);
                }
            }
        }


//    for (auto list : visited){
//        for (auto n : list){
//            cout << n;
//        }
//        cout << endl;
//    }
//    cout << endl;

        for(int i=0; i<lst1.size(); i++){
            if(visited[lst1[i]][lst2[i]])
                cout << 0;
            else
                cout << 1;
        }
        cout << endl;




    }


    return 0;
}
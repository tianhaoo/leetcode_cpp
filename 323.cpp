// 323. 无向图中连通分量的数目
//  dfs 并查集

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;



// class UF {
// public:
//     int count;
//     vector<int> parent;
//
//     UF(int n){
//         count = n;
//         parent.resize(n);
//         for (int i = 0; i < n; ++i) {
//             parent[i] = i;
//         }
//     }
//
//     void union_(int p, int q){
//         int rootP = find(p);
//         int rootQ = find(q);
//         if(rootP == rootQ) return;
//         parent[rootQ] = rootP;
//         count --;
//     }
//
//     int find(int x){
//         if(x != parent[x]){
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
//
//     bool connected(int p, int q){
//         return find(p) == find(q);
//     }
// };
//
// // 并查集版本
// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         auto uf = UF(n);
//         for (const auto &edge: edges) {
//             int ai = edge[0], bi = edge[1];
//             uf.union_(ai, bi);
//         }
//         return uf.count;
//     }
// };


// dfs版
class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int i){
        if(visited[i]){
            return;
        }
        visited[i] = true;
        for (const auto &neighbour: graph[i]) {
            dfs(graph, visited, neighbour);
        }
    }

   int countComponents(int n, vector<vector<int>>& edges) {
       // 根据边建图
       vector<vector<int>> graph(n, vector<int>());
       for (const auto &edge: edges) {
           int ai = edge[0], bi = edge[1];
           graph[ai].push_back(bi);
           graph[bi].push_back(ai);
       }

       vector<bool> visited(n, false);
       int count = 0;
       for (int i = 0; i < n; ++i) {
           if(!visited[i]){
               dfs(graph, visited, i);
               count ++;
           }
       }
        return count;
   }
};






int main() {

    int n = 5;
    // vector<vector<int>> edges = {
    //         {0, 1},
    //         {1, 2},
    //         {3, 4},
    // };
    vector<vector<int>> edges = {
            {0, 1},
            {1, 2},
            {0, 2},
            {3, 4},
    };
    auto solution = Solution();
    auto res = solution.countComponents(n, edges);
    cout << res << endl;

    return 0;
}

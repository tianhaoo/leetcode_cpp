// 886. 可能的二分法
// 图
// 二分图


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &color, bool &ok, int i){
        if (!ok){
            return;
        }
        visited[i] = true;
        for (const auto &neighbour: graph[i]) {
            if(!visited[neighbour]){
                color[neighbour] = !color[i];
                dfs(graph, visited, color, ok, neighbour);
            }else{
                if(color[neighbour] == color[i]){
                    ok = false;
                    return;
                }
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 建图
        vector<vector<int>> graph(n, vector<int>());
        for (const auto &dislike: dislikes) {
            int ai = dislike[0], bi = dislike[1];
            graph[ai-1].push_back(bi-1);
            graph[bi-1].push_back(ai-1);
        }

        vector<bool> visited(n, false);
        vector<bool> color(n, false);
        bool ok = true;
        for (int i = 0; i < graph.size(); ++i) {
            if(!visited[i]){
                dfs(graph, visited, color, ok, i);
                if(!ok){
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    int n = 4;
    vector<vector<int>> graph = {
            {1, 2},
            {1, 3},
            {2, 4}
    };
    auto solution = Solution();
    auto res = solution.possibleBipartition(n, graph);
    cout << res << endl;

    return 0;
}

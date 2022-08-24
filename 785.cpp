// 785. 判断二分图
// 图
// 二分图

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;

//// DFS版本
//class Solution {
//public:
//
//    void traverse(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &color, bool &ok, int i){
//        if (!ok){
//            return;
//        }
//
//        visited[i] = true;
//        for (const auto &j: graph[i]) {
//            if(!visited[j]){
//                // 给每个邻居j上色，和父节点i的颜色不同。
//                color[j] = !color[i];
//                traverse(graph, visited, color, ok, j);
//            }else{
//                // 访问过的节点，比较一下i和j的颜色。
//                if (color[i] == color[j]){
//                    ok = false;
//                    return;
//                }
//            }
//        }
//    }
//
//    bool isBipartite(vector<vector<int>>& graph) {
//        vector<bool> visited(graph.size(), false);
//        vector<bool> color(graph.size(), false);
//        bool ok = true;
//        for (int i = 0; i < graph.size(); ++i) {
//            if(!visited[i]){
//                traverse(graph, visited, color, ok, i);
//            }
//        }
//        return ok;
//    }
//};


// BFS版本
class Solution {
public:


    void bfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &color, bool &ok, int i){
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            auto sz = q.size();
            // 一次性遍历一层
            for (int j = 0; j < sz; ++j) {
                auto node = q.front();
                q.pop();
                visited[node] = true;
                for (const auto &neighbour: graph[node]) {
                    if( !visited[neighbour]){
                        color[neighbour] = ! color[node];
                        q.push(neighbour);
                    }else{
                        if(color[node] == color[neighbour]){
                            ok = false;
                            return;
                        }
                    }
                }
            }

        }
    }


    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> color(graph.size(), false);
        bool ok = true;
        for (int i = 0; i < graph.size(); ++i) {
            if(!visited[i]){
                bfs(graph, visited, color, ok, i);
                if(!ok){
                    return false;
                }
            }
        }
        return true;
    }
};




int main() {
//    vector<vector<int>> graph = {
//            {1, 2, 3},
//            {0, 2},
//            {0, 1, 3},
//            {0, 2}
//    };
    vector<vector<int>> graph = {
            {1, 3},
            {0, 2},
            {1, 3},
            {0, 2}
    };

    auto solution = Solution();
    auto res = solution.isBipartite(graph);
    cout << res << endl;

    return 0;
}

// 207. 课程表
// 图

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;

class Solution {
public:
    void traverse(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &onPath, int i, bool &hasCycle){
        if(onPath[i]){
            hasCycle = true;
        }
        if(visited[i] || hasCycle){
            return;
        }
        visited[i] = true;

        onPath[i] = true;
        for (int j = 0; j < graph[i].size(); ++j) {
            traverse(graph, visited, onPath, graph[i][j], hasCycle);
        }
        onPath[i] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 先建图
        vector<vector<int>> graph(numCourses, vector<int>());
        for (const auto &lst: prerequisites) {
            int ai = lst[0], bi = lst[1];
            graph[bi].push_back(ai);
        }
        printAdjList(graph);

        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if(!visited[i]){
                vector<bool> onPath(numCourses, false);
                bool hasCycle = false;
                traverse(graph, visited, onPath, i, hasCycle);
                if (hasCycle)
                    return false;
            }
        }
        return true;
    }
};


int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    // vector<vector<int>> prerequisites = {{1,0}, {0,1}};

    auto solution = Solution();
    auto res = solution.canFinish(numCourses, prerequisites);
    cout << res << endl;


    return 0;
}

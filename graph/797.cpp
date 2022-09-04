// 797. 所有可能的路径
// 图


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;



class Solution {
public:
    void traverse(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &path, int i){
        path.push_back(i);
        if(i == graph.size()-1){
            res.push_back(path);
        }
        for (int j = 0; j < graph[i].size(); ++j) {
            traverse(graph, res, path, graph[i][j]);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        if (graph.empty()){
            return res;
        }
        vector<int> path;
        traverse(graph, res, path, 0);
        return res;
    }
};

int main() {
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    auto solution = Solution();
    auto res = solution.allPathsSourceTarget(graph);
    printMatrix(res);

    return 0;
}

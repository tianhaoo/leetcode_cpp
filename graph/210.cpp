// 210. 课程表 II
// 图


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;

//// 后序遍历然后逆序输出
//class Solution {
//public:
//    void traverse(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &onPath, bool &hasCycle, int i, vector<int> &order){
//        if(onPath[i]){
//            hasCycle = true;
//        }
//        if(visited[i] || hasCycle){
//            return;
//        }
//        visited[i] = true;
//        onPath[i] = true;
//        for (int j = 0; j < graph[i].size(); ++j) {
//            traverse(graph, visited, onPath, hasCycle, graph[i][j], order);
//        }
//        onPath[i] = false;
//        order.push_back(i);
//    }
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        vector<int> order;
//        if (numCourses == 1){
//            order.push_back(0);
//            return order;
//        }
//
//        // 先建图
//        vector<vector<int>> graph(numCourses, vector<int>());
//        for (const auto &item: prerequisites) {
//            int ai = item[0], bi = item[1];
//            graph[bi].push_back(ai);
//        }
//        printAdjList(graph);
//
//        vector<bool> visited(numCourses, false);
//        vector<bool> onPath(numCourses, false);
//        bool hasCycle= false;
//        for (int i = 0; i < numCourses; ++i) {
//            if(!visited[i]){
//                traverse(graph,visited, onPath, hasCycle, i, order);
//                if(hasCycle)
//                    return {};
//            }
//        }
//        reverse(order.begin(), order.end());
//        return order;
//    }
//};


// BFS 找入度为0
class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        if(numCourses == 1){
            order.push_back(0);
            return order;
        }
        if(prerequisites.empty()){
            for (int i = 0; i < numCourses; ++i) {
                order.push_back(i);
            }
            return order;
        }
        // 先建图
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> rudu(numCourses, 0); // 记录所有节点的入度
        for (const auto &item: prerequisites) {
            int ai = item[0], bi = item[1];
            graph[bi].push_back(ai);
            rudu[ai] ++;
        }
        printAdjList(graph);
        printVector(rudu);

        queue<int> q;
        for (int node = 0; node < numCourses; ++node) {
            if(rudu[node] == 0){
                q.push(node);
            }
        }
        while(!q.empty()){
            auto sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                for (int n : graph[node]) {
                    rudu[n] --;
                    if(rudu[n] == 0){
                        q.push(n);
                    }
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};


int main() {
//    int numCourses = 4;
//    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
//    int numCourses = 2;
//    vector<vector<int>> prerequisites = {{0,1}};
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1,0},{1,2},{0,1}};


    auto solution = Solution();
    auto res = solution.findOrder(numCourses, prerequisites);
    printVector(res);


    return 0;
}

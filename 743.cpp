// 743. 网络延迟时间
// 图



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;

struct Edge{
    int toNode;
    int weight;
    Edge(int t, int w){
        toNode = t;
        weight = w;
    }
};


struct State{
    int node;
    int distFromStart;
    State(int n, int d){
        node = n;
        distFromStart = d;
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 建图
        vector<vector<Edge>> graph(n);
        for (int i = 0; i < times.size(); ++i) {
            int from=times[i][0]-1, to=times[i][1]-1, weight=times[i][2];
            graph[from].emplace_back(to, weight);
        }
        vector<int> distanceFromStartTo(n, 0);
        // 广度优先遍历，同时记录从节点k到每个节点的最短路径
        auto cmp = [](State &a, State &b){return a.distFromStart > b.distFromStart;};
        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        pq.push(State(k-1, 0));
        distanceFromStartTo[k-1] = 0;
        while(!pq.empty()){
            auto state = pq.top();
            pq.pop();

            if(distanceFromStartTo[state.node] < state.distFromStart) continue;

            for (const auto &item: graph[state.node]) {
                int newDistance = state.distFromStart + item.weight;
                if(newDistance < distanceFromStartTo[item.toNode]){
                    distanceFromStartTo[item.toNode] = newDistance;
                    pq.push(State(item.toNode, newDistance));
                }
            }

        }
        printVector(distanceFromStartTo);
        auto maxElementP = max_element(distanceFromStartTo.begin(), distanceFromStartTo.end());\
        return *maxElementP;

    }
};


int main() {

    int n = 4;
    int k = 2;
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};

    auto solution = Solution();
    auto res = solution.networkDelayTime(times, n, k);
    cout << res << endl;

    return 0;
}

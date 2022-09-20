// dijkstra最短路径算法
// 求从一个起点到n个终点的最短路径
// 利用贪心思想, 每次选比较短的边
// 时间复杂度v^2, 使用优先队列可以优化至e+vlogv
// 不适用于权重有负数的情况



#include "../utils.h"

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


struct Edge{int from, to, weight;};




int main() {

    int n = 4;  // 共几个节点
    vector<vector<long long>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};

    vector<vector<Edge>> graph(n);
    for(auto e:edges){
        int from = e[0];
        int to = e[1];
        int weight = e[2];
        graph[from].push_back({from, to, weight});
        graph[to].push_back({to, from, weight});
    }

    int from=0;

    vector<int> dis(n, INT_MAX);  // 记录从from到所有点的最短距离
    vector<bool> visited(n, false);  // 记录点是否被访问过

    // 比较两个节点谁距离from比较近
    auto cmp = [](const Edge a, const Edge b){
        return a.weight > b.weight;
    };
    priority_queue<Edge, vector<Edge>, decltype(cmp)> q(cmp);


    dis[from] = 0; // 自己到自己的距离为0
    visited[from] = true;
    // 先把from的邻接点放进队列
    for(auto e:graph[from]){
        q.push(e);
    }


    while(!q.empty()){
        Edge cur = q.top();
        q.pop();
        visited[cur.to] = true;

        dis[cur.to] = dis[cur.from] + cur.weight;

        for(auto nei:graph[cur.to]){
            if(!visited[nei.to]){
                q.push(nei);
            }
        }
    }

    printVector(dis);



    return 0;
}

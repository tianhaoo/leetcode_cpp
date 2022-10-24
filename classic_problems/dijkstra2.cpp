// dijkstra最短路径算法
// 求从一个起点到n个终点的最短路径
// 利用贪心思想, 每次选比较短的边
// 时间复杂度 使用优先队列 优化至e+vlogv
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


struct Edge{int to, weight;};



void path(vector<int> &middle, int to){
    if(middle[to] < 0){
        printf("%d\n", to);
        return;
    }
    printf("%d ", to);
    path(middle, middle[to]);
}



int main() {

    int n = 4;  // 共几个节点
    vector<vector<long long>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};

    vector<vector<Edge>> graph(n);
    for(auto e:edges){
        int from = e[0];
        int to = e[1];
        int weight = e[2];
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    int from = 0;  // 指定起始点

    vector<int> dis(n, INT_MAX);  // 记录从from到所有点的最短距离
    unordered_set<int> s;
    // 先都放在u里，s是空集

    auto cmp = [dis](Edge &a, Edge &b){
        return dis[a.to] > dis[b.to];
    };


    dis[from] = 0; // 自己到自己的距离为0
    s.insert(from);

    // 先把from到邻接点的最短距离更新一下
    for(auto e:graph[from]){
        dis[e.to] = e.weight;
    }


    priority_queue<pair<int, int>> u;
    // 把from的邻接点放进优先队列
    for(auto e:graph[from]){
        u.push(make_pair(dis[e.to], e.to));
    }

    vector<int> middle(n, -1); // 记录中间节点

    while(!u.empty()){
        // 找到u里距离from最近的点
        // 这里使用优先队列进行优化
        // int d=INT_MAX, st=0;
        // for(auto v: u){
        //     if(d >= dis[v]){
        //         d = dis[v];
        //         st = v;
        //     }
        // }
        auto temp = u.top();
        u.pop();
        int d = temp.first, st = temp.second;

        // 将最短的路 的目的点 作为中间点，更新dis数组, 只能更新st的邻接点
        for(auto e:graph[st]){
            long long p1 = dis[st] + e.weight;
            long long p2 = dis[e.to];
            if(p1 < p2){
                dis[e.to] = p1;
                middle[e.to] = st;
            }
            if(!s.count(e.to)){
                u.push(make_pair(dis[e.to], e.to));
            }

        }
        // 将st加入s
        s.insert(st);

    }

    printVector(dis);
    printVector(middle);
    path(middle, 3);
    return 0;
}

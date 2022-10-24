// Floyd最短路径
// 求任意两点之间的最短路径
// 动态规划 每次记录已经求得的最短路径长度
// 时间复杂度 v^3



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


// 根据插点输出单条最短路径经过的所有节点
void path(vector<vector<int>> &middle, int from, int to){
    if(middle[from][to] == INT_MAX){
        return;
    }
    int k = middle[from][to];
    path(middle, from, k);
    printf("%d ", k);
    path(middle, k, to);

}


int main() {

    int n = 4;  // 共5个节点
    vector<vector<long long>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};

    // 用long long 存,这样INTMAX加起来的时候就不会溢出
    vector<vector<long long>> dis(n, vector<long long>(n, INT_MAX));  // 存放每个节点到其他节点的最短距离
    // 根据已知的weight更新已知的最短路径长度.
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }
    for(auto e:edges){
        dis[e[0]][e[1]] = e[2];
        dis[e[1]][e[0]] = e[2];
    }
    vector<vector<int>> middle(n, vector<int>(n, INT_MAX));

    printMatrix(dis);

    for(int k=0; k<n; ++k){  // 对于每个插点
        for(int from=0; from<n; ++from){
            for (int to = 0; to < n; ++to) {
                if(dis[from][to] > dis[from][k] + dis[k][to]){
                    dis[from][to] = dis[from][k] + dis[k][to];
                    middle[from][to] = k; // 记录实际使用的最好的插点
                }
            }
        }
    }
    printMatrix(dis);
    printMatrix(middle);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("from: %d, to: %d, dis: %d; path: ",i, j, dis[i][j]);
            printf("%d ", i);
            path(middle, i, j);
            printf("%d\n", j);
        }
    }
    path(middle, 0, n-1);

    return 0;
}

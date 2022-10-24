// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 小红、小明正在和小猴子玩游戏。他们现在正在一颗大树上，树上有很多个落脚点。他们想要到同一个落脚点进行游戏， 不幸的是他们当前可能不在同一个落脚点。现在他们想找到一个用来集合的落脚点，使得他们到达那个落脚点需要走的路程之和最小。
//
// 形式化地，将落脚点称为节点，我们有一棵有n个节点的树（树是一种无向无环连通图），其中小红在A节点，小明在B节点，小猴子在C节点，他们想要找到一个节点M，使得AM+BM+CM最小(XY代表X到Y的最短距离)。
//
// 1<=n<=100,000，1<=u,v,A,B,C<=n，1<=w<=10,000
//
//
//
// 输入描述
// 第一行输入一个整数n，表示节点数。
//
// 第二行n-1个整数，第i个整数p[i]，表示点i+1与点p[i]之间有一条边。
//
// 第三行n-1个整数，第i个整数p[i]，表示点i+1与点p[i]之间的边的长度。
//
// 接下来一行三个整数A,B,C，表示小红小明小猴子所在的落脚点。
//
// 输出描述
// 输出一行，表示AM+BM+CM的最小值
//
//
// 样例输入
// 3
// 1 2
// 3 4
// 1 2 3
// 样例输出
// 7
//
// 提示
// 样例的树可以表示为
//
//
//
// 选择点1作为点M，AM=0，BM=3，CM=7，AM+BM+CM=10。
//
// 选择点2作为点M，AM=3，BM=0，CM=4，AM+BM+CM=7。
//
// 选择点3作为点M，AM=7，BM=4，CM=0，AM+BM+CM=11。
//
// 因此选择点2作为点M，答案为7。



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
#include <list>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;

const int inf = INT_MAX / 2;

vector<int> sp(vector<vector<int>>& times, int n, int k) {
    // 建图
    vector<vector<int>> g(n, vector<int>(n, inf));
    for(auto &t : times){
        int x = t[0] - 1, y = t[1] - 1;
        g[x][y] = t[2];
        g[y][x] = t[2];
    }
    vector<int> dist(n, inf);
    dist[k-1] = 0;
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        int x = -1;
        for (int j = 0; j <n; ++j) {
            if(!used[j] && (x==-1 || dist[j] < dist[x])){
                x = j;
            }
        }
        used[x] = true;
        for (int j = 0; j < n; ++j) {
            dist[j] = min(dist[j], dist[x] + g[x][j]);
        }
    }
    return dist;
}


int main() {
    int n;
    while(cin>>n){
        vector<int> edge(n-1), weight(n-1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> edge[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            cin >> weight[i];
        }
        int a, b, c;
        cin >> a >> b >> c;

        if(n == 1){
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> times;
        for (int i = 0; i < n - 1; ++i) {
            times.push_back({i+2, edge[i], weight[i]});
        }

        auto dist1 = sp(times, n, a);
        auto dist2 = sp(times, n, b);
        auto dist3 = sp(times, n, c);
        printVector(dist1);
        printVector(dist2);
        printVector(dist3);

        int m = INT_MAX;
        for(int mid=0; mid<n; mid++){
            int d = dist1[mid] + dist2[mid] + dist3[mid];
            m = min(m, d);
        }
        cout << m << endl;
    }

    return 0;
}





// floyed

// int main() {
//     int n;
//     while(cin>>n){
//         vector<int> edge(n-1), weight(n-1);
//         for (int i = 0; i < n - 1; ++i) {
//             cin >> edge[i];
//         }
//         for (int i = 0; i < n - 1; ++i) {
//             cin >> weight[i];
//         }
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--;
//         b--;
//         c--;
//
//         if(n == 1){
//             cout << 0 << endl;
//             continue;
//         }
//
//
//         vector<vector<long long>> dis(n, vector<long long>(n, INT_MAX));  // 存放每个节点到其他节点的最短距离
//
//         // 根据已知的weight更新已知的最短路径长度.
//         for (int i = 0; i < n; ++i) {
//             dis[i][i] = 0;
//         }
//         for (int i = 0; i < n - 1; ++i) {
//             // 把直接相连的边更新到dis数组里
//             int from = i;
//             int to = edge[i];
//             int w = weight[i];
//             dis[from][to] = w;
//             dis[to][from] = w;
//         }
//
//
//
//         for(int k=0; k<n; ++k){  // 对于每个插点
//             for(int from=0; from<n; ++from){
//                 for (int to = 0; to < n; ++to) {
//                     if(dis[from][to] > dis[from][k] + dis[k][to]){
//                         dis[from][to] = dis[from][k] + dis[k][to];
//                     }
//                 }
//             }
//         }
//
//
//
//         long long m = INT_MAX;
//         for(int mid=0; mid<n; mid++){
//             long long d = dis[a][mid] + dis[b][mid] + dis[c][mid];
//             m = min(m, d);
//         }
//         cout << m << endl;
//
//     }
//
//     return 0;
// }

// 1135. 最低成本联通所有城市
// 图 最小生成树
// 克鲁斯卡尔 prim


#include <vector>
#include <string>
#include "../utils.h"

using namespace std;


// class UF{
// public:
//     int count;
//     vector<int> parent;
//     UF(int n){
//         count = n;
//         parent.resize(n);
//         for (int i = 0; i < n; ++i) {
//             parent[i] = i;
//         }
//     }
//     void union_(int p, int q){
//         int rootP = find(p);
//         int rootQ = find(q);
//         if(rootP == rootQ){
//             return;
//         }else{
//             parent[rootP] = rootQ;
//             count --;
//         }
//     }
//     int find(int x){
//         if(parent[x] != x){
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
//     bool connected(int p, int q){
//         return find(p) == find(q);
//     }
// };
//
// // 克鲁斯卡尔
// class Solution {
// public:
//     int minimumCost(int n, vector<vector<int>>& connections) {
//         // 将edges 根据cost排序
//         printMatrix(connections);
//         sort(connections.begin(), connections.end(), [](vector<int> lst1, vector<int> lst2){return lst1[2] < lst2[2];});
//         printMatrix(connections);
//
//         UF uf(n);
//
//         int total_cost = 0;
//
//         for (const auto &connection: connections) {
//             int a=connection[0]-1, b=connection[1]-1, cost=connection[2];
//             if(! uf.connected(a, b)){
//                 uf.union_(a, b);
//                 total_cost += cost;
//             }
//         }
//
//         if(uf.count > 1){
//             return -1;
//         }else{
//             return total_cost;
//         }
//     }
// };


struct ArcNode{
    int toVertex;
    int weight;
    ArcNode(int t, int w){
        toVertex = t;
        weight = w;
    }

};


// Prim算法
class Solution {
public:


    int minimumCost(int n, vector<vector<int>>& connections) {
        // 先建图
        vector<vector<ArcNode>> graph(n, vector<ArcNode>());
        for (const auto &connection: connections) {
            int from=connection[0]-1, to=connection[1]-1, weight=connection[2];
            graph[from].emplace_back(to, weight);
            graph[to].emplace_back(from, weight); // 连接是双向的
        }

        // 然后实施Prim算法
        int weightSum=0; // 记录所有的权重和
        vector<bool> inTree(n, false);
        auto cmp = [](ArcNode &a, ArcNode &b){return a.weight > b.weight;};
        priority_queue<ArcNode, vector<ArcNode>, decltype(cmp)> pq(cmp);
        // 先将0节点加入树，然后将他的所有边放进优先队列。
        inTree[0] = true;
        for (const auto &arc: graph[0]) {
            pq.push(arc);
        }
        while(!pq.empty()){
            auto m = pq.top();
            pq.pop();
            if(inTree[m.toVertex]) continue;
            inTree[m.toVertex] = true;
            weightSum += m.weight;
            for (const auto &arc: graph[m.toVertex]) {
                pq.push(arc);
            }
        }
        for (int i = 0; i < n; ++i) {
            if(!inTree[i]) return -1;
        }
        return weightSum;
    }
};



int main(){
    int n = 5;
    // vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
    vector<vector<int>> connections = {{2,1,50459},{3,2,47477},{4,2,52585},{5,3,16477}};
    auto solution = Solution();
    auto res = solution.minimumCost(n, connections);
    cout << res << endl;


    return 0;
}

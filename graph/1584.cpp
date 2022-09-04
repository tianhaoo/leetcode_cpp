// 1584. 连接所有点的最小费用
// 图 最小生成树


#include <vector>
#include <string>
#include "../utils.h"

#include <ctime>

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
//     void join(int p, int q){
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
//
//
// //边结构及边表 因为要排序，所以需要用一个数据结构将边长和索引信息绑起来
// struct Edge{
//     int length;
//     int from;
//     int to;
//     Edge(int l, int _i, int _j): length(l), from(_i), to(_j){}
// };
//
//
// // 克鲁斯卡尔
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         UF uf(n);
//         vector<Edge> edges;
//
//         // 先生成任意一点到其他点的距离存起来
//         // 同时生成所有的边
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if(i == j) continue;
//                 edges.emplace_back(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j);
//             }
//         }
//         // 给边按照cost排序
//         sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.length < b.length;});
//         // 从cost最小的边开始遍历
//         int total_cost=0;
//         for (const auto &edge: edges) {
//             if(!uf.connected(edge.from, edge.to)){
//                 uf.join(edge.from, edge.to);
//                 total_cost += edge.length;
//             }
//             if(uf.count == 1) break;
//         }
//         return total_cost;
//     }
// };






struct Edge{
    int toVertex;
    int weight;
    Edge(int t, int w){
        toVertex = t;
        weight = w;
    }
};

// Prim算法
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int weightSum = 0;

        // 先建图
        int n = points.size();
        vector<vector<Edge>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i==j) continue; // 不允许自己连自己
                graph[i].emplace_back(j, abs(points[j][0]-points[i][0]) + abs(points[j][1] - points[i][1]));
            }
        }

        // 生成优先队列
        vector<bool> inTree(n, false);
        auto cmp = [](Edge &a, Edge &b){return a.weight > b.weight;};
        priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
        inTree[0] = true;
        for (const auto &edge: graph[0]) {
            pq.push(edge);
        }
        while(!pq.empty()){
            auto edge = pq.top();
            pq.pop();
            if(inTree[edge.toVertex]) continue;
            inTree[edge.toVertex] = true;
            weightSum += edge.weight;
            for (const auto &e: graph[edge.toVertex]) {
                pq.push(e);
            }
        }

        for (int i = 0; i < n; ++i) {
            if(!inTree[i]) return -1;
        }
        return weightSum;
    }
};



int main() {

    // vector<vector<int>> points = {{75,790},{767,519},{405,210},{-526,-175},{-126,-824},{382,862},{-832,630},{-23,-463},{62,-480},{371,724},{280,-645},{144,-115},{-212,-990},{-856,-393},{43,-429},{959,880},{267,-876},{-212,500},{-699,-240},{349,-745},{-558,92},{-52,-619},{269,282},{-403,-921},{-848,-406},{-737,-453},{335,-521},{-914,953},{-612,-268},{-133,238},{304,-477},{-312,-565},{-643,-114},{908,923},{946,-296},{-1000,-464},{770,405},{-491,543},{439,199},{31,182},{-362,790},{956,935},{-913,-368},{-766,449},{-103,96},{551,-792},{-136,456},{29,592},{462,-813},{859,-832},{-22,-987},{-762,686},{-483,281},{-115,1000},{40,-978},{993,-85},{-516,662},{797,-968},{106,-578},{-517,1000},{535,-696},{-140,-821},{-843,831},{-918,704},{-679,375},{475,105},{-293,1000},{-80,809},{-600,783},{-210,-810},{260,-234},{-374,-488},{-640,820},{-717,23},{-729,-282},{534,-752},{-775,-493},{796,-39},{-403,531},{665,543},{-51,71},{-321,576},{-513,-665},{-510,-38},{733,576},{567,461},{46,-985},{199,-462},{-145,833},{888,908},{-148,445},{-542,-432},{-277,-735},{-564,-428},{-88,790},{495,-227},{-794,83},{-691,-677},{-3,901},{999,-22},{2,408},{-300,482},{-650,-54},{-425,-875},{-163,959},{-609,123},{491,765},{-126,253},{-147,971},{-991,952},{-917,-928},{891,-717},{-232,-173},{231,-335},{869,-890},{369,-108},{708,874},{-452,785},{921,-333},{625,-257},{-490,666},{-271,974},{599,-691},{634,-731},{630,901},{426,-293},{229,-753},{-668,-371},{311,-928},{569,-154},{-766,-232},{847,-457},{48,56},{583,201},{-799,-744},{-119,-967},{-261,-970},{-100,-379},{91,-909},{7,631},{-163,-962},{-979,144},{-590,779},{30,-453},{-300,-488},{-360,-960},{-498,-465},{-753,436},{-193,-494},{-480,-730},{130,-77},{966,694},{121,-420},{359,736},{-717,683},{-786,-619},{357,-58},{163,172},{960,-153},{-89,-536},{-374,-4},{342,-493},{-631,350},{859,682},{777,954},{-124,948},{636,-79},{-587,609},{427,-816},{-856,-672},{828,152},{828,192},{-791,737},{155,-723},{-940,632},{-460,22},{519,-687},{-848,48},{535,-168},{442,304},{-267,436},{-309,-280},{160,-63},{440,229},{732,42},{592,531},{347,-494},{919,-663},{474,941},{88,-405},{-403,-529},{988,342}};
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    auto solution = Solution();

    auto begin = clock();
    auto res = solution.minCostConnectPoints(points);
    auto end = clock();

    cout << res << endl;

    // 计算运行时间
    auto time = (double) (end - begin) / CLK_TCK;
    cout << time << endl;

    return 0;
}

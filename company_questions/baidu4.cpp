// 小红走矩阵


#include "../utils.h"


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



unordered_map<char, char> forbiddenTo = {
        {'r', 'd'},
        {'e', 'r'},
        {'d', 'e'},
};

unordered_map<char, char> forbiddenFrom = {
        {'r', 'e'},
        {'e', 'd'},
        {'d', 'r'},
};

vector<vector<int>> directions = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

DECLARE_PRINT

struct State{
    int id;
    int distFromStart;
    State(int i, int d):id(i), distFromStart(d){}
};

vector<int> dijkstra(int start, vector<vector<int>> &graph, int n, int m){
    int v = n*m-1;
    vector<int> distTo(v, INT_MAX);
    distTo[start] = 0;
    auto cmp = [](State &a, State &b){return a.distFromStart > b.distFromStart;};
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
    pq.push(State(start, 0));

    while(!pq.empty()){
        State curState = pq.top();
        int curId = curState.id;
        int curDistFromStart = curState.distFromStart;

        if(curDistFromStart > distTo[curId]){
            continue;
        }
        for(int nextNodeID : graph[curId]){
            int distToNextNode = distTo[curNode]
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m){
        vector<string> matrix(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }

        // 先建图
        vector<vector<int>> graph(n * m + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int fromNode = i * m + j;
                for(auto direction : directions) {
                    int nextI = i + direction[0];
                    int nextJ = j + direction[1];
                    if(nextI >= 0 && nextI <= n-1 && nextJ >= 0 && nextJ <= m-1){
                        int toNode = nextI * m + nextJ;
                        if(matrix[nextI][nextJ] != forbiddenTo[matrix[i][j]]){
                            graph[fromNode].push_back(toNode);
                        }
                    }
                }
            }
        }

        printAdjList(graph);

    }

    return 0;
}

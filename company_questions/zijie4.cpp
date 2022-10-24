//
// Created by Tiana on 2022/10/9.
//



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


int count(int cur, vector<bool> &visited, vector<vector<int>> &graph){

    int count=0;
    for(int i=0; i<graph[cur].size(); ++i){

    }
}


int main() {
    int n;
    while(cin >> n){
        int u, v;
        vector<vector<int>> graph(n+1, vector<int>());
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        printAdjList(graph);

        string res(n, 'B');


        cout << res << endl;
    }

    return 0;
}

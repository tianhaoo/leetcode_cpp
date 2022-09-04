// 261. 以图判树
// 图 并查集


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;


class UF{
public:
    int count;
    vector<int> parent;
    UF(int n){
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    void union_(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ){
            return;
        }else{
            parent[rootQ] = rootP;
            count --;
        }


    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool connected(int p, int q){
        return find(p) == find(q);
    }
};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UF uf(n);
        for (const auto &edge: edges) {
            int a = edge[0], b = edge[1];
            if (uf.connected(a, b)){
                return false;
            }else{
                uf.union_(a, b);
            }
        }
        return uf.count == 1;
    }
};


int main() {

    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {2, 3}};
    auto solution = Solution();
    auto res = solution.validTree(n, edges);
    cout << res << endl;

    return 0;
}

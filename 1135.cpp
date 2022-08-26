// 1135. 最低成本联通所有城市
// 图 最小生成树


#include <vector>
#include <string>
#include "utils.h"

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
            parent[rootP] = rootQ;
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
    int minimumCost(int n, vector<vector<int>>& connections) {
        // 将edges 根据cost排序
        printMatrix(connections);
        sort(connections.begin(), connections.end(), [](vector<int> lst1, vector<int> lst2){return lst1[2] < lst2[2];});
        printMatrix(connections);

        UF uf(n);

        int total_cost = 0;

        for (const auto &connection: connections) {
            int a=connection[0]-1, b=connection[1]-1, cost=connection[2];
            if(! uf.connected(a, b)){
                uf.union_(a, b);
                total_cost += cost;
            }
        }

        if(uf.count > 1){
            return -1;
        }else{
            return total_cost;
        }
    }
};


int main(){
    int n = 3;
    vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
    auto solution = Solution();
    auto res = solution.minimumCost(n, connections);
    cout << res << endl;


    return 0;
}

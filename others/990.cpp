// 990. 等式方程的可满足性
// 并查集


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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (const auto &equation: equations) {
            if(equation[1] == '='){
                int a = equation[0] - 'a';
                int b = equation[3] - 'a';
                uf.union_(a, b);
            }
        }
        for (const auto &equation: equations) {
            if(equation[1] == '!'){
                int a = equation[0] - 'a';
                int b = equation[3] - 'a';
                if(uf.connected(a, b)){
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {

    // vector<string> equations = {"a==b","b!=a"};
    vector<string> equations = {"a==b","e==c","b==c","a!=e"};
    auto solution = Solution();
    auto res = solution.equationsPossible(equations);
    cout << res << endl;

    return 0;
}

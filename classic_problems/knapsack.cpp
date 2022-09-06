// 01背包问题



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <random>
#include "../utils.h"

using namespace std;


struct Bag{
    int value;
    int weight;
    Bag(int v, int w){
        value = v;
        weight = w;
    }
};


void backtrack(vector<int> & weight, vector<int> &value, int n, int w, int &maxValue, Bag &bag, int start){
    if(bag.weight > w){
        return;
    }
    if(start >= n){
        maxValue = max(maxValue, bag.value);
        return;
    }


    for(auto take : {true, false}){
        if(take){
            bag.weight += weight[start];
            bag.value += value[start];
        }
        backtrack(weight, value, n, w, maxValue, bag, start+1);
        if(take){
            bag.weight -= weight[start];
            bag.value -= value[start];
        }
    }
}


// 暴力穷举
int bf(vector<int> & weight, vector<int> &value, int n, int w){
    Bag bag(0, 0);
    int maxValue = INT_MIN;
    backtrack(weight, value, n, w, maxValue, bag, 0);
    return maxValue;

}



// 重量限制为j的时候，装前i件物品，返回最大价值
int dp(vector<int> &weight, vector<int> &value, int i, int j, vector<vector<int>> &memo){


    if(i<0 || j<=0){
        return 0;
    }
    if(memo[i][j] != INT_MIN){
        return memo[i][j];
    }

    // 能装得下就装第i件物品
    int p1 = INT_MIN;
    if(weight[i] <= j){
        p1 = value[i] + dp(weight, value, i-1, j-weight[i], memo);
    }

    // 不装第i件物品
    int p2 = dp(weight, value, i-1, j, memo);

    int res = max(p1, p2);
    memo[i][j] = res;

    return res;
}



int main() {
    default_random_engine e;

    int n = 3000;  // n件物品
    int w = n*50;  // 重量限制为w
    vector<int> weight;
    vector<int> value;
    uniform_int_distribution<int> u1(0, 500);
    for (int i = 0; i < n; ++i) {
        weight.push_back(u1(e));
    }
    uniform_int_distribution<int> u2(0, 1000);
    for (int i = 0; i < n; ++i) {
        value.push_back(u2(e));
    }

    vector<vector<int>> memo(n+1, vector<int>(w+1, INT_MIN));
    auto mt = MyTimer();
    int res = dp(weight, value, n-1, w, memo);
    cout << res << endl;

    // auto mt = MyTimer();
    // int ans = bf(weight, value, n, w);
    // cout << ans << endl;



    return 0;
}

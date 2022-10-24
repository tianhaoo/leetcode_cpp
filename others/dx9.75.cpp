// 9.75 单调队列 连续子序列的最大和


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


int main() {

    vector<int> lst = {2, -3, 5, 2, -4, -1, 8};
    int m=3;


    // 先转成前缀和数组
    vector<int> preSum;

    int sum =0;
    for(int i=0; i<lst.size(); ++i){
        sum += lst[i];
        preSum.push_back(sum);
    }

    vector<int> res;
    deque<int> q; // 记录前m个前缀和，单调递增队列






    return 0;
}

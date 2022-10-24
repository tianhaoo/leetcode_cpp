// 121. 买卖股票的最佳时机



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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 遍历一遍，把第i天之前的最低价格记录下来，假设再史低低价格买入，第i天卖出
        int historyMin=INT_MAX, res = INT_MIN;
        for(int i=0; i<prices.size(); ++i){
            historyMin = min(historyMin, prices[i]);
            res = max(res, prices[i]-historyMin);
        }
        return res;

    }
};


int main() {

    return 0;
}

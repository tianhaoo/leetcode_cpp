// 739. 每日温度
// 单调栈




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include "utils.h"

using namespace std;

struct info{
    int temperature;
    int index;
    info(int t, int i){
        temperature = t;
        index = i;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<info> s;
        vector<int> ans(temperatures.size(), 0);
        for(int i=temperatures.size()-1; i>=0; --i){
            while(!s.empty() && temperatures[i] >= s.top().temperature){
                s.pop();
            }
            ans[i] = s.empty() ? 0 : (s.top().index-i);
            s.push(info(temperatures[i], i));
        }
        return ans;
    }
};


int main() {
    vector<int> temperatures = {47,47,46,76,100,70};
    auto solution = Solution();
    auto res = solution.dailyTemperatures(temperatures);
    printVector(res);

    return 0;
}

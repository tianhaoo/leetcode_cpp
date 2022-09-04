// 239. 滑动窗口最大值
// 单调队列




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return {};
    }
};


int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto solution = Solution();
    auto res = solution.maxSlidingWindow(nums, k);
    printVector(res);
    return 0;
}

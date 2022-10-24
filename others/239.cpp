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
    deque<int> q;  // 队列里面放的是下标
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        for(int i=0; i<k; i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);

        int head=0;
        for(int tail=k; tail<nums.size(); tail++){
            // 先入队
            while(!q.empty() && nums[q.back()] < nums[tail]){
                q.pop_back();
            }
            q.push_back(tail);

            // 再出队
            if(q.front() == head){
                q.pop_front();
            }
            head ++;

            res.push_back(nums[q.front()]);
        }
        return res;
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

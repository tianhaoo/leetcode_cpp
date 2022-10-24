// 031. 下一个排列


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
    // 升序排列是最小的，降序排列是最大的
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        // 先从后往前找到第一个相邻升序对
        int i, j;
        for(j=nums.size()-1; j>=1; --j){
            i = j-1;
            if(nums[i] < nums[j]){
                break;
            }
        }
        // 然后从后往前找到第一个比i大的,记为k
        int k;
        for(k=nums.size()-1; k>i; k--){
            if(nums[k] > nums[i]){
                break;
            }
        }
        // 交换i和k
        int tmp = nums[i];
        nums[i] = nums[k];
        nums[k] = tmp;
        // 此时[j...end]必然是降序,逆置使其升序
        reverse(nums.begin()+j, nums.end());



    }
};


int main() {
    vector<int> nums = {1};
    auto solution = Solution();
    solution.nextPermutation(nums);


    printVector(nums);

    return 0;
}

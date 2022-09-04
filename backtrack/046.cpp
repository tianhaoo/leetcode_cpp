// 46. 全排列
// 回溯

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;


class Solution {
    vector<bool> used;
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, vector<int> path){
        if(path.size() == nums.size()){
            res.push_back(path);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if(!used[i]){
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, path);
                used[i] = false;
                path.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        vector<int> path;
        backtrack(nums, path);
        return res;

    }
};


int main() {
    vector<int> nums = {1,2,3};
    auto solution = Solution();
    auto res = solution.permute(nums);
    for (const auto &lst: res) {
        printVector(lst);
    }

    return 0;
}

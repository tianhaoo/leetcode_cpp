// 1984. 学生分数的最小差值
// 滑动窗口

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>


using namespace std;



class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left=0, right=0;
        int res=INT_MAX;
        while (right < nums.size()){
            // a 是将要移入窗口的元素
            int a = nums[right];
            right++;

            while (right-left>=k){
                // b 是将要移出的元素
                int b=nums[left];
                int diff = a-b;
                res = min(res, diff);
                left ++;
            }

        }
        return res;

    }
};

int main() {
    vector<int> nums = {9,4,1,7};
    int k = 2;

    auto s = Solution();
    int diff = s.minimumDifference(nums, k);
    cout << diff << endl;

    return 0;
}

// 42. 接雨水
// 暴力，备忘录，双指针
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;

// // 备忘录
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> left_max(n);
//         vector<int> right_max(n);
//         int m;
//
//         m = INT_MIN;
//         left_max[0] = 0;
//         for (int i = 1; i < n; ++i) {
//             m = max(m, height[i-1]);
//             left_max[i] = m;
//         }
//         m = INT_MIN;
//         right_max[n-1] = 0;
//         for (int i = n-2; i >= 0; --i) {
//             m = max(m, height[i+1]);
//             right_max[i] = m;
//         }
//
//         int res = 0;
//         for (int i = 0; i < n; ++i) {
//             res += max(
//                     min(left_max[i], right_max[i]) - height[i],
//                     0
//             );
//         }
//
//         return res;
//     }
// };

// 双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int left_max = INT_MIN, right_max = INT_MIN;

        int res=0;
        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max){
                res += left_max - height[left];
                left++;
            }else{
                res += right_max - height[right];
                right--;
            }
        }


        return res;
    }
};


int main() {
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> height = {4,2,0,3,2,5};
    // vector<int> height = {4, 2, 0, 3, 2, 5};
    vector<int> height = {1};

    auto solution = Solution();
    auto res = solution.trap(height);
    cout << res << endl;

    return 0;
}

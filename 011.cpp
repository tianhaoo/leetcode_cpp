// 11. 盛最多水的容器
// 暴力 双指针

#include <vector>
#include <string>
#include "utils.h"

using namespace std;

// // 暴力做法
// class Solution {
// public:
//     int s(vector<int>& height, int a, int b){
//         return (b-a) * min(height[a], height[b]);
//     }
//     int res = INT_MIN;
//     int maxArea(vector<int>& height) {
//         for (int i = 0; i < height.size(); ++i) {
//             for (int j = i+1; j < height.size(); ++j) {
//                 res = max(res, s(height, i, j));
//             }
//         }
//         return res;
//     }
//
// };

// 双指针
class Solution {
public:
    int s(vector<int>& height, int a, int b){
        return (b-a) * min(height[a], height[b]);
    }

    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int current_max = INT_MIN;
        int res = INT_MIN;
        while(left < right){
            current_max = max(current_max, s(height, left, right));
            res = max(res, current_max);
            if (height[left] < height[right]){
                left ++;
            }else{
                right --;
            }
        }
        return res;
    }

};


int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    // vector<int> height = {1,1};
    auto solution = Solution();
    auto res = solution.maxArea(height);
    cout << res << endl;

    return 0;
}

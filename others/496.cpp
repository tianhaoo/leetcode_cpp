// 496. 下一个更大元素 I
// 单调栈



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include "../utils.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int i = nums2.size()-1; i>=0; --i) {
            while(!s.empty() && nums2[i] < s.top()){
                s.pop();
            }
            m[nums2[i]] = s.empty()? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> res;
        for (const auto &n: nums1) {
            res.push_back(m[n]);
        }
        return res;
    }

    vector<int> beforeLesserElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int i = 0; i<nums2.size(); ++i) {
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            m[nums2[i]] = s.empty()? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> res;
        for (const auto &n: nums1) {
            res.push_back(m[n]);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 3, 2, 4, 6, 5};
    vector<int> nums2 = {1, 3, 2, 4, 6, 5};
    auto solution = Solution();
    auto res = solution.beforeLesserElement(nums1, nums2);
    auto res2 = solution.nextGreaterElement(nums1, nums2);
    printVector(res);
    printVector(res2);

    return 0;
}

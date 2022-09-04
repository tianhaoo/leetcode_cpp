// 1464. 数组中两元素的最大乘积
// 堆

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a, b;
        make_heap(nums.begin(), nums.end());
        pop_heap(nums.begin(), nums.end());
        a = nums.back();
        nums.pop_back();
        pop_heap(nums.begin(), nums.end());
        b = nums.back();
        nums.pop_back();
        return (a-1)*(b-1);
    }
};

int main() {

    return 0;
}

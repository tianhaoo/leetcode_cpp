// 153. 寻找旋转排序数组中的最小值
// 二分查找
#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = INT_MAX;
        for (auto elem : nums){
            m = min(m, elem);
        }
        return m;
    }
};


int main(){
    auto s = Solution();
    vector<int> lst = {1, 2, 3, 4, 5, 6, 7};

    cout << s.findMin(lst) << endl;

    return 0;
}

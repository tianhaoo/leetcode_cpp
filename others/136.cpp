// 136. 只出现一次的数字
// 异或有交换律定理，相当于将相同的数字先异或，这样两两异或就只剩0了，然后0再和最后的一个数字异或得到最终值
// 相同的数异或为0  0和任何数字异或结果不变


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
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto n : nums){
            res = res ^ n;
        }
        return res;
    }
};


int main() {

    vector<int> lst = {4,1,2,1,2};
    auto solution = Solution();
    auto res = solution.singleNumber(lst);
    cout << res << endl;


    return 0;
}

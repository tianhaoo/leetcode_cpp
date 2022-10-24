// 三数之和
//
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
//
// 注意：答案中不可以包含重复的三元组。
//
//
//
// 示例 1：
//
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 示例 2：
//
// 输入：nums = []
// 输出：[]
// 示例 3：
//
// 输入：nums = [0]
// 输出：[]
//



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


struct index{
    vector<int> lst;
};



vector<int> twoSum(vector<int> &lst, unordered_map<int, index> &m, int target){
    vector<int> res;
    for (int i = 0; i < lst.size(); ++i) {
        int temp = lst[i];
        auto indexes = m[target-temp];
    }

}


vector<int> threeSum(vector<int> &lst, int target){
    unordered_map<int, int> m;
    for (int i = 0; i < lst.size(); ++i) {

    }
}


int main() {

    vector<int> lst = {-1,0,1,2,-1,-4};

    unordered_map<int, index> m;  // 记录元素所在的下标
    for (int i = 0; i < lst.size(); ++i) {
        m[i].lst.push_back(i);
    }



    return 0;
}

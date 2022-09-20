
// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 小美正在监控从上游服务器过来的数据流。正常情况下，数据流应该是单调递增的一列数。但是今天由于一系列网络波动，某些数据发生了错位。小美认为，如果数据流中某个数前面的所有数都比它小且后面的所有数都比它大，那么这个数是正常的，否则是不正常的。现在小美想知道今天的数据流中有哪些数是正常的。
//
//
//
// 输入描述
// 第一行有一个正整数n(2<=n<=100000)，代表数据流中数的个数。
//
// 第二行有n个两两不同的正整数，依次代表数据流中的数。数据流中的数的范围在1到1000000000之间。
//
// 输出描述
// 在第一行中输出正常的数的数量。
//
// 在第二行中输出所有正常的数的位置，以空格分隔，行末不能有空格。
//
// 可以参考样例。
//
//
// 样例输入
// 6
// 1 3 2 4 6 5
// 样例输出
// 2
// 1 4


#include "../utils.h"


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
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


bool check(vector<long long> &lst, int i){
    long long temp = lst[i];
    for (int j = 0; j < i; ++j) {
        if(lst[j] > temp){
            return false;
        }
    }
    for (int j = i+1; j < lst.size(); ++j) {
        if(lst[j] < temp){
            return false;
        }
    }
    return true;
}



class Solution {
public:
    vector<long long> nextGreaterElement(vector<long long>& nums1, vector<long long>& nums2) {
        stack<long long> s;
        unordered_map<long long, long long> m;
        for (int i = nums2.size()-1; i>=0; --i) {
            while(!s.empty() && nums2[i] < s.top()){
                s.pop();
            }
            m[nums2[i]] = s.empty()? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<long long> res;
        for (const auto &n: nums1) {
            res.push_back(m[n]);
        }
        return res;
    }

    vector<long long> beforeLesserElement(vector<long long>& nums1, vector<long long>& nums2) {
        stack<long long> s;
        unordered_map<long long, long long> m;
        for (int i = 0; i<nums2.size(); ++i) {
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            m[nums2[i]] = s.empty()? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<long long> res;
        for (const auto &n: nums1) {
            res.push_back(m[n]);
        }
        return res;
    }
};


int main() {

    int n;
    while(cin >> n){
        vector<long long> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }

        // vector<long long> res;
        // for (int i = 0; i < n; ++i) {
        //     if(check(lst, i)){
        //         res.push_back(lst[i]);
        //     }
        // }


        auto solution = Solution();
        auto r1 = solution.beforeLesserElement(lst, lst);
        auto r2 = solution.nextGreaterElement(lst, lst);


        vector<long long> res;
        for (int i = 0; i < n; ++i) {
            if(r1[i] == -1 && r2[i]==-1){
                res.push_back(lst[i]);
            }
        }

        cout << res.size() << endl;

        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if(i < res.size()-1){
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

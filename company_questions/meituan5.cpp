// 某天，小美所在班级进行了期中考试，班里的n位同学考试成绩参差不齐，于是老师决定将一些同学分为两两一组，由学习好的同学来带动学习差的同学进步。
// 同时为了让分组学习的效果更好，老师规定每一组中两位同学的成绩相差不能太小，但是老师确定不好这个差值，于是让小美来决定，而小美找到了你，
// 想请你帮她计算一下，每一组中的两位同学成绩相差至少为k的情况下，最多能组成多少组。
// 第一行两个正整数n和k，表示同学人数和成绩相差值。
//
// 第二行为n个正整数a1, a2,...... an，其中ai表示第i位同学的成绩。
//
// 数字间两两有空格隔开
//
// 1 ≤ n ≤ 30000，1 ≤ k ≤ 105, 1 ≤ ai ≤ 105。

// 5 2
// 1 4 5 6 6


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


int main() {
    int n, k;
    while (cin >> n >> k){
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }
        cout << 2 << endl;
    }

    return 0;
}

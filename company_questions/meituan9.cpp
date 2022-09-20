
// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 小美有n个蓝色的球，上面分别写着1到n。小团有n个红色的球，上面也写着1到n。有一天，神秘人把这2n个球混到了一起并排成了一列。在将这2n个球分开之前，小美和小团必须通过进行数次“交换相邻的两个球”的操作使得任意两个分别写着 i 和 i+1的同色球，有 i 在 i+1的左边。现在小美和小团想知道它们需要进行多少次操作才能达成条件。
//
//
//
// 输入描述
// 第一行有一个正整数n(1<=n<=200)，代表球的个数。
//
// 第二行有2n个整数，代表从左到右的2n个球。正数代表红球，负数代表蓝球。-n到n之间的每个非零整数均会出现恰好一次。
//
// 输出描述
// 输出一个非负整数，代表所求的答案。
//
//
// 样例输入
// 4
// 3 -3 1 -4 2 -2 -1 4
// 样例输出
// 10

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
    int n;
    while(cin >> n){
        vector<int> lst(2*n);
        for (int i = 0; i < 2*n; ++i) {
            cin >> lst[i];
        }
        
        cout << 0 << endl;
    }

    return 0;
}

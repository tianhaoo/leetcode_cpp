// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 现在给你一堆卡片。每张卡片上有一个数字。
//
// 小明想要从数字1开始连续地收集卡片，即收集完数字1就收集数字2，然后收集数字3，依次类推。
//
// 显然，小明会在收集到某个数字的时候，发现卡片中已经没有这个数字了。
//
// 那么，现在的问题是，小明最多可以收集到数字几呢？
//
// 1<=n<=10000
//
// 对全体卡片均保证其上的数字范围在[1, n]之间
//
//
//
// 输入描述
// 第一行，一个正整数n
//
// 第二行，n个正整数，表示这n张卡牌的数值。
//
// 注意：不保证卡牌按大小顺序给出。
//
// 输出描述
// 一行一个自然数，表示小明能收集到数字几。若小明连数字1都无法收集，则输出0。
//
//
// 样例输入
// 5
// 1 2 3 2 1
// 样例输出
// 3


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


int main() {
    int n;
    while (cin >> n){
        set<int> s;
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            s.insert(temp);
        }
        int want = 1;
        int index = 0;
        for(int i : s){
            if(i != want){
                break;
            }else{
                want ++;
            }
        }
        cout << want-1 << endl;
    }

    return 0;
}

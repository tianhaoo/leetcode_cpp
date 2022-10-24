// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 给定字符串1和字符串2，要求从串1中删去若干字符，变成串2。
//
// 若存在这样的删除方法输出yes，不能则输出no
//
//
//
// 输入输出以多组数据给出。
//
// n <= 100，每组数据中两个串的长度均不超过1000
//
//
//
// 输入描述
// 第一行一个正整数n，表示有n组询问
//
// 对于每组数据给出两行字符串，第一行为串1，第二行为串2。
//
// 串中仅包含小写字母。
//
// 输出描述
// 对于n组询问每组询问均输出一行yes或no
//
//
// 样例输入
// 5
// yesyes
// yes
// yyyeeesss
// yes
// yeyeyeseses
// yes
// sey
// yes
// yssssssseyyyy
// yes
// 样例输出
// yes
// yes
// yes
// no
// no


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
        for (int i = 0; i < n; ++i) {
            string from, to;
            cin >> from >> to;
            int p1=0, p2=0;
            while(p1 <from.size() && p2<to.size()){
                if(from[p1] == to[p2]){
                    p1 ++;
                    p2 ++;
                }else{
                    p1++;
                }
            }
            if(p2 == to.size()){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}

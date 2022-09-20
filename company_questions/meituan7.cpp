// 小团所在的游戏工会最近接到了许多相同的任务。每个任务都需要两位玩家组队参与。设组队的两个玩家的等级分别为a和b，则a+b必须大于等于x 且a*b必须大于等于y。现在小团想知道在工会内部有多少合法的组队方式。
// 第一行有三个正整数n,x,y(2<=n<=100000,1<=x,y<=1000000)，分别代表工会中的玩家数，组队玩家等级之和的下限，组队玩家等级之积的下限。
//
// 第二行有n个数，第i个代表工会中第i个玩家的等级。
//
// 等级均为不超过1000的正整数。
//
// 数字间两两有空格隔开。

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
    int n, x, y;
    while (cin >> n >> x >> y){
        vector<int> dengji(n);
        for (int i = 0; i < n; ++i) {
            cin >> dengji[i];
        }
        sort(dengji.begin(), dengji.end());
        auto lst = vector<int>(dengji.rbegin(), dengji.rend());
        printVector(lst);

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int a=lst[i];
            for (int j = i+1; j < n; ++j) {
                int b=lst[j];
                cout << a << ", " << b << endl;
                if(a+b>=x && a*b >=y){
                    count ++;
                }else{
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

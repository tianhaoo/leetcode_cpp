// 某天，小美在玩一款游戏，游戏开始时，有n台机器，每台机器都有一个能量水平，分别为a1、a2、…、an，小美每次操作可以选其中的一台机器，假设选的是第i台，
// 那小美可以将其变成 ai+10k（k为正整数且0≤k≤9），由于能量过高会有安全隐患，所以机器会在小美每次操作后会自动释放过高的能量，即变成 (ai+10k)%m，
// 其中%m表示对m取模，由于小美还有工作没有完成，所以她想请你帮她计算一下，对于每台机器，将其调节至能量水平为0至少需要多少次操作（机器自动释放能量不计入小美的操作次数）。


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


// 返回从machine到km的最小操作次数
int distance(int machine, int km){
    // machine 一定是小于m的
    int diff = km - machine;
    // 返回diff的各个位之和
    int temp = diff;
    int sum = 0;
    while(temp > 0){
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

// 返回最小操作次数
int caozuo(int machine, int m){
    // 从k = 1开始查找,
    // machie是奇数 m是偶数就找到km的个位数是machine+1
    // machie是奇数 如果m是奇数就找到km的个位数是machine
    // machine是偶数，m偶数， 直到 km的个位数是machine
    // machine偶数，m奇数，直到machine+1

    int target;
    if((machine%2 != 0 && m%2 == 0) || (machine%2==0 && m%2 != 0)){  // 到machine+1
        target = machine + 1;
    }else{
        target = machine;
    }

    int k=1;
    int minCao = INT_MAX;
    while((k*m) % 10 != target){
        minCao = min(minCao, distance(machine, k*m));
        k ++;
    }

    return distance(machine, k*m);

}


int main() {
    int n, m;
    unordered_map<string, int> memo;
    while (cin >> n >> m){
        int machine;
        for (int i = 0; i < n; ++i) {
            cin >> machine;
            if(machine <= 0){
                cout << 0;
            }else{
                string key = to_string(machine) + ","+ to_string(m);
                if(memo.count(key)){
                    return memo[key];
                }
                int res = caozuo(machine, m);
                memo[key] = res;
                cout << res;
            }

            if(i != n-1){
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

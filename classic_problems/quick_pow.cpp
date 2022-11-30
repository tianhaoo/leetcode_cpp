// 快速幂
// 求 a的n次方，时间复杂度 log_2^n

// 对指数n做二进制拆分，例如，3^13 = 3^(1101)_2 = 3^8 * 3^4 * 3^1
// 每次对a平方倍增


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


int quickpow(int a, int n){
    int res = 1;
    while(n){  // 直到n为0
        if(n & 1){ // 如果n最后一位是1的话
            res = res*a;
        }
        a = a*a;
        n = n >> 1;  // 右移一位,相当于给n除以2
    }
    return res;
}

// 带模数的快速幂
int quickpow(int a, int n, int p){
    int res = 1;
    while(n){
        if(n & 1){
            res = (res*a)%p;
        }
        a = (a*a) % p;
        n = n >> 1;
    }
    return res;
}


int main() {
    int mod = quickpow(10, 9) + 7;
    cout << mod + 10 << endl;
    cout << quickpow(mod + 10, 1, mod) << endl;
    
    cout << quickpow(10, 1) << endl;

    return 0;
}

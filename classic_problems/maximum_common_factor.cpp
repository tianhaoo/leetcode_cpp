// 求a和b的最大公因数



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
#include <random>
#include "../utils.h"

using namespace std;


// 暴力枚举法
// 从1到较小数的一半，每个试一下是不是公因数
int gcd1(int a, int b){
    int small = min(a, b);
    if(max(a, b) % small == 0){
        return small;
    }
    for(int i=2; i<small/2; i++){
        if (a%i == 0 && b%i == 0){
            return i;
        }
    }
    return -1;
}


// 辗转相除法
// 两个正整数a和b（a>b），它们的最大公约数等于a除以b的余数c和b之间的最大公约数。
// 比如10和25，25除以10商2余5,那么10和25的最大公约数，等同于10和5的最大公约数。
int gcd2(int big, int small){
    int res = big % small;
    if(res == 0){
        return small;
    }
    return(gcd2(small, res));
}

// 更相减损术
// 两个正整数a和b（a>b），它们的最大公约数等于a-b的差值c和较小数b的最大公约数。
// 比如10和25，25减去10的差是15,那么10和25的最大公约数，等同于10和15的最大公约数。
int gcd3(int big, int small){
    int diff = big-small;
    if(diff == 0){
        return small;
    }
    if(small >= diff){
        return gcd3(small, diff);
    }else{
        return gcd3(diff, small);
    }
}




int main() {

    cout << gcd1(7, 5) << endl;
    cout << gcd2(7, 5) << endl;
    cout << gcd3(25, 15) << endl;

    cout << 2 % 3 << endl;
    return 0;
}

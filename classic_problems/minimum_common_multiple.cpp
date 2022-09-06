// 求最小公倍数



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


// 定理；
// a，b两数的最小公倍数等于 他们的乘积除以 其 最大公约数

int gcd(int big, int small){
    if(big % small == 0){
        return small;
    }
    return gcd(small, big%small);
}

int beishu(int a, int b){
    return a * b / gcd(max(a,b), min(a,b));
}


int main() {

    return 0;
}

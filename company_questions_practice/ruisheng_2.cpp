// 十进制转n进制
// n进制转10进制

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


vector<char> base = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


// 整数部分, 除 N 取余，逆序排列
// 小数部分, 乘 N 取整，顺序排列
string convert10ToN(int num, int n){
    string res="";
    while(num != 0){
        res.push_back(base[num % n]);
        num = num / n;
    }
    return string(res.rbegin(), res.rend());
}

// 按权相加
// 对于整数部分，从右往左看，第 i 位的位权等于N^(i-1)
// 对于小数部分，恰好相反，要从左往右看，第 j 位的位权为N^-j。
int convertNTo10(string s, int n){
    int res = 0;
    int count = 0;
    for(int i=s.size()-1; i>=0; --i){
        res += pow(n, count++);
    }
    return res;
}


int main() {
    int num = 15;
    int n = 16;
    cout << convert10ToN(num, n) << endl;

    string s = "11";
    n = 2;
    cout << convertNTo10(s, n) << endl;

    return 0;
}

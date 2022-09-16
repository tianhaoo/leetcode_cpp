//
// Created by Tiana on 2022/9/14.
//



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
    long long n;
    while (cin >> n){
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 2){
            cout << 20 << endl;
            continue;
        }
        long long sum=0;
        long long cornor = 4;
        long long edge = (n-2) * 4;
        long long other = n*n - edge - cornor;
        long long maxNum = 0;
        for (long long i = 1; i <= cornor; ++i) {
            sum += i*2;
        }
        for (long long i = cornor+1; i <= cornor+ edge; ++i) {
            sum += (i*3)%1000000007;
        }
        long long a1 = cornor+ edge+1;
        long long end = n*n;
        long long number = end - a1 + 1;
        long long res = ((a1 + end) / 2) %1000000007;
        res = res * 4 % 1000000007;
        res = res * number % 1000000007;
        cout << (sum + res)%1000000007 << endl;

    }

    return 0;
}

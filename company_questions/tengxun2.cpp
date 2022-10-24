//
// Created by Tiana on 2022/10/16.
//



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

int count(int x){
    int count = 0;
    while(x!=0){
        ++count;
        x = (x-1) & x;
    }
    return count;
}


int main() {
    int n, k;
    while (cin >> n >> k){
        int sum = 0;

        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
            sum += lst[i];
        }


        auto cmp = [lst](int a, int b){return (a - count(a)) < (b - count(b));};
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

        for (int i = 0; i < n; ++i) {
            q.push(lst[i]);
        }

        for (int i = 0; i < k; ++i) {
            int num = q.top();
            int new_num = count(num);
            q.pop();
            q.push(new_num);
            sum -= num;
            sum += new_num;
        }

        cout << sum << endl;


    }

    return 0;
}

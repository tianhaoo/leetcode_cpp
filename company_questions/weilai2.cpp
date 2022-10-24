//
// Created by Tiana on 2022/9/22.
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


int main() {
    int n;
    while (cin >> n){
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }
        sort(lst.begin(), lst.end());
        int m = INT_MIN;
        for(int i=1; i<lst.size(); ++i){
            m = max(m, lst[i]-lst[i-1]);
        }
        cout << m << endl;
    }

    return 0;
}

//
// Created by Tiana on 2022/10/15.
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
    int n, k;
    while (cin >> n >> k){
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }

        if(n==2){
            int temp = abs(lst[0]-lst[1]);
            if( temp<= k){
                cout << 2 << endl;
            }else{
                cout << 1 << endl;
            }
        }

        sort(lst.begin(), lst.end());

        int res = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >=i+1; --j) {
                if(lst[j] - lst[i] > k){
                    continue;
                }else{
                    res = max(res, j-i+1);
                    break;
                }
            }
        }


        cout << res << endl;

    }

    return 0;
}

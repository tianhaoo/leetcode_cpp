//
// Created by Tiana on 2022/10/24.
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
    int n, m;
    double p;
    while(cin >> n >> m >> p){
        vector<vector<double>> price(m, vector<double>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> price[i][j];
            }
        }
        
        cout << m- m* p << endl;
    }

    return 0;
}

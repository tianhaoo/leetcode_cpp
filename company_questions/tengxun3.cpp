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


int main() {
    int n;
    while(cin >> n){
        deque<int> q;
        int  temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            q.push_back(temp);
        }
        vector<int> res;

        for (int i = 0; i < n; ++i) {
            int begin = q.front();
            int end = q.back();
            if((i+1)%2!=0){
                // 大Q

                if(begin > end){
                    q.pop_front();
                    res.push_back(begin);
                }else{
                    q.pop_back();
                    res.push_back(end);
                }
            }else{
                // 小Q
                if(begin > end){
                    q.pop_back();
                    res.push_back(end);
                }else{
                    q.pop_front();
                    res.push_back(begin);
                }
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if(i<res.size()-1){
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

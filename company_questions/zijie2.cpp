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
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }
        unordered_set<int> s1, s2;
        int count=0;
        for (int i = 0; i < n; ++i) {
            if(s1.count(lst[i])){
                count++;
                continue;
            }
            if(s2.count(lst[i])){
                continue;
            }

            int flag = true;
            for (int j = 0; j < n; ++j) {
                if(lst[i] % lst[j] != 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                s1.insert(lst[i]);
                count ++;
            }else{
                s2.insert(lst[i]);
            }
        }
        cout << count << endl;
    }

    return 0;
}

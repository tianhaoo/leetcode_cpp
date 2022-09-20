//小团喜欢完整且连续的东西，比如连续的一段整数，如3 4 5 6 7。如果一个数组在按升序或降序排序之后是连续的一段整数，那么他会觉得这个数组很好看。
// 现在小团有一个可能不那么好看的数组，而他想通过数次形如“将第k个元素加1”或“将第k个元素减1”的操作将其变成好看的数组。
// 他想知道至少要进行多少次操作才能将他的这个数组变成他认为好看的数组。

// 5
// 7 3 11 5 2

// 7

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



int change(vector<int> &from, vector<int> &to, int n){
    vector<int> sameTo(n, -1);  // 下标 和 值的相同
    vector<int> sameFrom(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(from[i] == to[j]){
                sameTo[i] = j;
                sameFrom[j] = i;
            }
        }
    }
    vector<int> fromLst, toLst;
    for (int i = 0; i < n; ++i) {
        if(sameTo[i]==-1){
            fromLst.push_back(from[i]);
        }
        if(sameFrom[i]==-1){
            toLst.push_back(to[i]);
        }
    }
    int sum=0;
    for (int i = 0; i < fromLst.size(); ++i) {
        sum += abs(fromLst[i]-toLst[i]);
    }
    return sum;
}


int main() {
    int n;
    while (cin >> n){
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }
        sort(lst.begin(), lst.end());
        vector<vector<int>> candidates;

        for (int i = 0; i < n/2+10; ++i) {
            vector<int> temp(n);
            int t=lst[i];
            for (int j = 0; j < n; ++j) {
                temp[j] = t;
                t++;
            }
            candidates.push_back(temp);
        }

        for (int i = int(n/2)-10; i < n; ++i) {
            vector<int> temp(n);
            int t=lst[i]-n-1;
            for (int j = 0; j < n; ++j) {
                temp[j] = t;
                t++;
            }
            candidates.push_back(temp);
        }


        int m = INT_MAX;
        for(auto can: candidates){
            int res = change(lst, can, n);
            m = min(m, res);
        }
        cout << m << endl;
    }

    return 0;
}

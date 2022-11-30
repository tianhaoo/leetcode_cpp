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

bool check(vector<int> &lstA, vector<int> &lstB, int a, int b){
    int sumA=0, sumB=0;
    sumA = accumulate(lstA.begin(), lstA.end(), 0);
    sumB = accumulate(lstB.begin(), lstB.end(), 0);

    int sumAGe = sumA % 10;
    int sumBGe = sumB % 10;
    if(
            (sumAGe == a && sumBGe == b) ||
            (lstA.empty() && sumBGe == a) ||
            (lstA.empty() && sumBGe == b)
    ){
        return true;
    }else{
        return false;
    }
}

void dfs(vector<int>& lstA, vector<int> &lstB, vector<int> &lst, int cur, int a, int b, int &count){
    if(cur >= lst.size()){
        if(check(lstA, lstB, a, b)){
            count++;
        }
        return;
    }
    lstA.push_back(lst[cur]);
    dfs(lstA, lstB, lst, cur+1, a, b, count);
    lstA.pop_back();

    lstB.push_back(lst[cur]);
    dfs(lstA, lstB, lst, cur+1, a, b, count);
    lstB.pop_back();
}


int main() {
    int n, a, b;
    while (cin >> n >> a >> b){
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }
        vector<int> lstA, lstB;
        int count = 0;
        dfs(lstA, lstB, lst, 0, a, b, count);
        cout << count << endl;

    }

    return 0;
}

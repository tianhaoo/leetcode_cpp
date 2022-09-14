//


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



void backtrack(vector<int> &lst, int m, int &count, string path, int start, vector<bool> &used){
    if (path.size() >= m){
        cout << path << endl;
        count++;
        return;
    }
    for(int i=start; i<lst.size(); ++i){
        if(lst[i] > 0){
            path.push_back(lst[i]+'0');
            lst[i] --;
            used[i] = true;
            backtrack(lst, m, count, path, start+1, used);
            path.pop_back();
            used[i] = false;
            lst[i] ++;
        }
    }

}

int main() {
    int n, m;
    while(cin >> n >> m){
        vector<int> lst(n);
        int temp;
        for(int i=0; i<n; ++i){
            cin >> temp;
            lst[i] = temp;
        }
        int count =0;
        vector<bool> used(n, false);
        backtrack(lst, m, count, "", 0, used);
        cout << count << endl;
    }



    return 0;
}

// 两个一组替换

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
#include <random>


using namespace std;


vector<int> findSame(string &s){
    vector<int> res;
    int p=0;
    while(p < s.size()-1){
        if(s[p] == s[p+1]){
            res.push_back(p);
            p++;
        }
        p++;
    }
    return res;
}


int main() {
    string s;
    while (cin >> s){
        auto lst = findSame(s);
        while(!lst.empty()){
            string newS;
            lst = findSame(newS);
        }




        cout << res << endl;
    }

    return 0;
}

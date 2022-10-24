//
// Created by Tiana on 2022/10/9.
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

struct Node{
    int to;
    int dis;
    Node(int t, int d):to(t), dis(d){}
};


int nextP(int p, vector<Node> & lst){
    int nextp=p;
    int curValue = lst[p].dis;
    while(nextp<lst.size()){
        if(lst[nextp].dis > curValue){
            break;
        }
        nextp++;
    }
    return nextp;
}

int main() {
    int n;
    while(cin >> n){
        vector<Node> lst;
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            lst.emplace_back(i+1, temp);
        }
        sort(lst.begin(), lst.end(), [](Node &a, Node &b){return a.dis < b.dis;});

        vector<pair<int, int>> res;

        int p = 0;
        int nextp = nextP(p, lst);

        while(p < lst.size()){
            if(nextp<lst.size() && lst[nextp].dis - lst[p].dis != 1){
                cout << nextp << ", " << p << endl;
                cout << -1 << endl;
                break;
            }
            int nextNextP = nextP(nextp, lst);
            for(int i=nextp; i<nextNextP; i++){
                res.emplace_back(lst[p].to, lst[i].to);
            }

            p =nextp;
            nextp = nextNextP;
        }
        cout << res.size() << endl;
        for(auto item:res){
            cout << item.first << ' ' << item.second << endl;
        }





    }
    return 0;
}

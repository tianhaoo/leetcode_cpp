//
// Created by Tiana on 2022/10/10.
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
    int id;
    int len;
    char yin;
    Node(int i, int l, int y):id(i), len(l), yin(y){};
};

int main() {
    string str;
    int k;
    while(cin >> str){
        cin >> k;

        auto cmp = [](Node &a, Node &b){return a.len > b.len;};
        priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);

        string yins;
        vector<int> lens;

        int index = 0;
        int id = 0;
        while(index < str.size()){
            char yin = str[index];
            int len = 1;
            int j;
            for (j=index + 1; j < str.size(); ++j) {
                if(str[j] == yin){
                    len ++;
                }else{
                    break;
                }
            }

            index = j;

            q.push(Node(id, len, yin));
            id ++;
            yins.push_back(yin);
            lens.push_back(len);
        }

        for (int i = 0; i < k; ++i) {
            auto node = q.top();
            node.len += 10;
            q.pop();
            q.push(node);
            lens[node.id] += 10;

            cout << node.id+1 << ' ' << node.yin << endl;
        }

        string res;
        for (int i = 0; i < yins.size(); ++i) {
            res.push_back(yins[i]);
            res.push_back('(');
            res+= to_string(lens[i]);
            res.push_back(')');
        }
        cout << res << endl;



    }

    return 0;
}

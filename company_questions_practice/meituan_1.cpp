// 美团骑手包裹区间分组




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
#include <climits>

using namespace std;

struct Info{
    int start;
    int end;
    Info(){
        start = INT_MIN;
        end = INT_MIN;
    }
    Info(int s, int e):start(s), end(e){}
};

int check(int start, int end, string &s, unordered_map<char, Info> &startAndEnd){
    // 检查从start到end是否都在里面
    int m = INT_MIN;
    for(int i=start; i<=end; ++i){
        m = max(m, startAndEnd[s[i]].end);
    }
    return max(m, end);
}

int main() {
    string s;
    unordered_map<char, Info> startAndEnd;  // 记录开始和结束的位置
    while (cin >> s){
        for(int i=0; i<s.size(); ++i){
            if(startAndEnd.count(s[i])){
                startAndEnd[s[i]].end = i;
            }else{
                startAndEnd[s[i]] = Info(i, i);
            }
        }


        vector<int> res;
        int start = 0, end = start;
        while(start < s.size() && end < s.size()){
            int nextEnd = check(start, end, s, startAndEnd);
            if(nextEnd == end){
                res.push_back(end+1-start);
                start = end+1;
                end = start;
            }else{
                end = nextEnd;
            }
        }

        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if(i !=res.size()-1){
                cout << ' ';
            }
        }
        cout << endl;


    }

    return 0;
}

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

void sortIndex(string &s, vector<int> &indexes, bool shengXu){
    vector<char> lst;
    for (int i: indexes) {
        lst.push_back(s[i]);
    }
    if(shengXu){
        sort(lst.begin(), lst.end(), less<int>());
    }else{
        sort(lst.begin(), lst.end(), greater<int>());
    }
    for (int i = 0; i < indexes.size(); ++i) {
        s[indexes[i]] = lst[i];
    }
}


int main() {
    string s;
    while(cin>>s){
        vector<int> numsIndex; // 存放所有数字的下标
        vector<vector<int>> splits; // 存放分割点二维数组
        vector<char> letters;
        bool cut = true;
        for(int i=0; i<s.size(); ++i){
            char c = s[i];
            if(c >= '0' && c <='9'){
                numsIndex.push_back(i);
                if(cut){
                    splits.push_back({i});
                    cut = false;
                }else{
                    splits.back().push_back(i);
                }
            }else{
                letters.push_back(c);
                cut = true;
            }
        }
        bool zhengTiSheng;

        if(numsIndex.size() == s.size()){
            // 没有字母的情况
            sort(s.begin(), s.end());
            cout << s << endl;

        } else if(numsIndex.size() == s.size() - 1){
            // 只有一个字母的情况
            zhengTiSheng = true;
            sortIndex(s, numsIndex, zhengTiSheng);
            cout << s << endl;
        }else{
            // 其他情况
            // 先确定整体是否升序
            if(letters.front() <= letters.back()){
                zhengTiSheng = true;
            }else{
                zhengTiSheng = false;
            }
            // 然后确定每个区间是否升序
            vector<bool> splitsSheng;
            for(auto range : splits){
                int left = range.front()-1;
                int right = range.back()+1;
                if(left<0 || right>=s.size() || left >=s.size() || right<0){
                    splitsSheng.push_back(zhengTiSheng);
                }else{
                    if(s[left]<=s[right]){
                        splitsSheng.push_back(true);
                    }else{
                        splitsSheng.push_back(false);
                    }
                }
            }

            // 先整体排序
            sortIndex(s, numsIndex, zhengTiSheng);

            // 然后对局部排序
            for (int i = 0; i < splits.size(); ++i) {
                sortIndex(s, splits[i], splitsSheng[i]);
            }
            cout << s << endl;
        }

    }

    return 0;
}

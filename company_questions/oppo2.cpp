//
// Created by Tiana on 2022/11/3.
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


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * findStr从反方向查找子串，返回最后一次匹配成功时，子串的偏移位置，如果没有匹配成功返回-1
     * @param str string字符串 待匹配的字符串
     * @param mod string字符串 匹配模式字符串
     * @return int整型
     */
    int findStr(string str, string mod) {
        bool hasStar = false;
        for (const auto &c: mod) {
            if(c == '*'){
                hasStar = true;
            }
        }
        if(!hasStar){
            bool ok = false;
            auto found = str.find_last_of(mod);
            while(found != string::npos){
                ok = true;
                found = str.find_last_of(mod, found-1);
                if(found == 0) break;
            }
            if(ok){
                return found;
            }else{
                return -1;
            }
        }else{
            return -1;
        }


    }
};


int main() {
    auto solution = Solution();
    string s1 = "Hello world Hello world";
    string s2 = "leH";
    auto res = solution.findStr(s1, s2);
    cout << res << endl;

    return 0;
}

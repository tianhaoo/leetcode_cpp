// 小明的一个工作是将只包含a~j的小写英文字母编码为八进制数字。规则是这样的，将a编码为0，b为1，c为2，d为3，e为4，f为5，g为6，h为7，i为10，j为11（注意上述数字均为八进制）。
//
// 小明将一大段文本已经正确编码为了一串数字了。但不幸的是原始文本看不见了。现在你对着编码后的数字串，想要知道原本有多少种小写英文字母的组合编码后变成这样。
// 3
// 111



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



int count(int n, map<int, int> &memo){
    if(n<=0){
        return 0;
    }
    if(n <= 2){
        return n;
    }
    if(memo.count(n)){
        return memo[n];
    }
    int res = 0;
    for(int i=0; i<n-1; ++i){
        // i 和 i+1
        int left = count(i, memo);
        int right = count(n-(i+2), memo);
        if(left == 0){
            res += right;
        }else if(right == 0){
            res += left;
        }else{
            res += left * right;
        }
    }
    res ++;
    memo[n] = res;
    return 1 + res;
}


int main() {
    int n;
    while(cin >> n){
        string s;
        cin >> s;

        // 先找出来所有 x个1 和 x个1+1个0
        vector<int> start, length;
        int p1=0, p2=0;
        while(p1 < s.size()){
            if(s[p1] == '1'){
                p2 = p1+1;
                while(p2 < s.size() && s[p2]=='1'){
                    p2++;
                }
                if(p2 > p1+1){
                    if(s[p2] == '0'){
                        p2 ++;
                    }
                    start.push_back(p1);
                    length.push_back(p2-p1);
                }
                p1 = p2;

            }else{
                p1++;
            }
        }
        // printVector(start);
        // printVector(length);
        // for(int i=0; i<start.size(); ++i){
        //     cout << s.substr(start[i], length[i]) << endl;
        // }

        map<int, int> memo;


        int sum = 1;
        for(int len:length){
            int temp = count(len, memo);
            sum *=temp;
            sum %= 1000000007;
        }
        cout << sum << endl;


    }

    return 0;
}

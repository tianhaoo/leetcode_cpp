// 如果一个字符串s只包含0或者1，那么这个串就叫做01串。
// 我们定义一个01串的大小为这个01串中1的个数减去0的个数。比如”00111”的大小就是3减去2，结果是1。一个字符串的子串就是这个字符串一段连续的区间，我们认为空串也是一个子串，现在你需要求出最大的01子串，只需要输出大小就行了。
// 7
// 0110111




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






int main() {
    int n;
    while(cin >> n){
        string s;
        cin >> s;

        unordered_map<char, int> need, window;

        int valid = 0; // 记录当前窗口内，合法字符的个数
        int min_len = INT_MAX;
        int min_len_start=0;

        int left=0, right=0;
        while(right < s.size()){
            char a = s[right];
            if (need.find(a)!=need.end()){
                window[a]++;
                if(window[a] == need[a]){
                    valid ++;
                }
            }
            right ++;

            while(valid == need.size()){
                //这里代表每次找到了一个合法的子串
                if (right-left < min_len){
                    min_len = right-left;
                    min_len_start = left;
                }
                char b = s[left];
                if(need.find(b) != need.end()){
                    if(window[b] == need[b]){
                        valid --;
                    }
                    window[b]--;
                }
                left++;
            }
        }
        if(min_len == INT_MAX){
            return "";
        }else{
            return s.substr(min_len_start, min_len);
        }


    }

    return 0;
}

// 76. 最小覆盖子串
// 滑动窗口


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need, window;
        for (const auto &c: t) {
            need[c]++;
        }
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
};

int main() {

    string s = "aab";
    string t = "aab";
    auto solution = Solution();
    string res = solution.minWindow(s, t);

    cout << res << endl;


    return 0;
}

// 3. 无重复字符的最长子串


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
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int left=0, right=0; // 左闭右开
        unordered_map<char, int> window;
        unordered_set<char> dup;
        int start=0, length=INT_MIN;
        while(right < s.size()){
            // 增大窗口
            char c = s[right];
            window[c] ++;
            if(window[c] >= 2){
                dup.insert(c);
            }
            right ++;

            while(dup.size() > 0){  // 窗口需要缩小
                // 缩小窗口
                char d = s[left];
                if(dup.count(d)){
                    dup.erase(d);
                }
                window[d] --;
                left ++;
            }
            // 更新最大值
            if(length < right-left){
                start = left;
                length = right-left;
            }
        }
        return length;
    }
};


int main() {
    string s = "pwwkew";
    auto solution = Solution();
    auto res = solution.lengthOfLongestSubstring(s);
    cout << res << endl;

    return 0;
}

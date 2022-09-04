// 680. 验证回文字符串 Ⅱ
// 双指针


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;

class Solution {
public:
    bool isHuiwen(string s, int left, int right){
        while (left < right){
            if(s[left] != s[right]){
                return false;
            }else{
                left ++;
                right--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left, right;
        left = 0;
        right = s.size()-1;
        while (left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else{
                return isHuiwen(s, left, right-1) || isHuiwen(s, left+1, right);
            }
        }
        return true;

    }
};


int main() {
    string s = "aba";
    auto solution = Solution();
    auto res = solution.validPalindrome(s);
    cout << res << endl;

    return 0;
}

//
// Created by 田浩 on 2022/8/5.
//
#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {


    void backtrack(const string& digits, string &combination){
        if (combination.length() == digits.length()){

        }

    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phoneMap = {
                {'2', "abc"}
                {'3', "def"}
                {'4', "ghi"}
                {'5', "jkl"}
                {'6', "mno"}
                {'7', "pqrs"}
                {'8', "tuv"}
                {'9', "wxyz"}
        }

    }

};

int main(){
    auto s = Solution();
    string digits = "23";
    auto res =  s.letterCombinations(digits);
    for (auto s : res){
        cout << s << endl;
    }
    return 0;
}
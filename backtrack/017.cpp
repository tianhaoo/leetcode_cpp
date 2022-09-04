// 17. 电话号码的字母组合
// 回溯法
#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {

    unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> combinations;


    void backtrack(const string& digits, string &combination, int index){
        if (combination.length() == digits.length()){
            combinations.push_back(combination);
        }else{
            char digit = digits[index];
            const string letters = phoneMap.at(digit);
            for (const char &letter : letters){
                combination.push_back(letter);
                backtrack(digits, combination, index+1);
                combination.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string combination;
        backtrack(digits, combination, 0);
        return combinations;
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
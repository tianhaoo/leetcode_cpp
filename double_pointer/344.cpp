// 344. 反转字符串
// 双指针

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    void swap(char &a, char&b){
        char temp = a;
        a = b;
        b = temp;
    }
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while (i < j){
            swap(s[i++], s[j--]);
        }
    }
};


int main() {

    return 0;
}

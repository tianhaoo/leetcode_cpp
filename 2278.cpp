//
// Created by Tiana on 2022/8/16.
//


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        auto cnt = count(s.begin(), s.end(), letter);
        return cnt * 100 / s.size();

    }
};




int main() {

    return 0;
}

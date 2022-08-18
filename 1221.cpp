// 1221. 分割平衡字符串
// 贪心

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    int balancedStringSplit(string s) {
        if (s.size() <=1){
            return 0;
        }
        int count = 1;
        char c=s[0];
        int res=0;
        for(int i=1; i<s.size(); i++){
            if(count == 0){
                c = s[i];
                count = 1;
                continue;
            }
            if(s[i] == c){
                count ++;
            }else{
                count --;
            }
            if(count == 0){
                res ++;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}

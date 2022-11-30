//
// Created by Tiana on 2022/11/3.
//



#include "../utils.h"


#include <cstdio>
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
#include <list>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


struct Res{
    char value;
    char jinwei;
    Res(char v, char j): value(v), jinwei(j){}
};

Res add(char a, char b, char jin){
    int res = a - '0' + b - '0' + jin - '0';
    int value = res % 10;
    int jinwei = res / 10;
    return {(char)(value+'0'), (char)(jinwei+'0')};
}

string add(string &a, string &b){
    // 补成一样长
    string temp(abs((int)a.size()-(int)b.size()), '0');
    if(a.size() < b.size()){
        a = temp + a;
    }
    if(b.size() < a.size()){
        b = temp + b;
    }
    string ans = "";
    char jin='0';
    for(int i=a.size()-1; i>=0; --i){
        auto res = add(a[i], b[i], jin);
        jin = res.jinwei;
        ans += res.value;
    }
    if(jin != '0'){
        ans += jin;
    }
    return string(ans.rbegin(), ans.rend());

}






int main() {
    int a;
    while(cin >> a){
        string s1 = to_string(a);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        cout << add(s1, s2) << endl;
    }

    return 0;
}

// baidu型子串



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


unordered_set<char> yuanyin = {'a', 'e', 'i', 'o', 'u'};


bool check(string &s, int left){
    unordered_set<char> st;
    char c;
    c = s[left];
    if(yuanyin.count(c)){
        return false;
    }
    st.insert(c);
    c = s[left+1];
    if(!yuanyin.count(c)){
        return false;
    }
    st.insert(c);
    c = s[left+2];
    if(!yuanyin.count(c)){
        return false;
    }
    st.insert(c);
    c = s[left+3];
    if(yuanyin.count(c)){
        return false;
    }
    st.insert(c);
    c = s[left+4];
    if(!yuanyin.count(c)){
        return false;
    }
    st.insert(c);
    return st.size() == 5;
}


int main() {
    string s;
    while(cin >> s){
        if(s.size() < 5){
            cout << 0 << endl;
            continue;
        }
        int sum = 0;
        for (int i = 0; i < s.size()-4; ++i) {
            if(check(s, i)){
                cout << s.substr(i, 5) << endl;
                sum ++;
            }
        }
        cout << sum << endl;
    }


    return 0;
}

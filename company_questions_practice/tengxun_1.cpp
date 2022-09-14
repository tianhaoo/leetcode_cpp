// 假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下：
// a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，
// aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.



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

// [96, 121]
void dfs(vector<string> &res, string &path, int n){
    if(n == 4){
        res.push_back(path);
        return;
    }
    for(int i=96; i<=121; ++i){
        path.push_back(char(i));
        dfs(res, path, n+1);
        path.pop_back();
    }
}




int main() {
    string s;
    unordered_map<string, int> memo;
    while (cin >> s){
        // 在高位补0
        int diff = 4-s.size();
        string diffString(diff, char(96));
        s = diffString + s;

        string base(4, char(96));
        int index=0;
        for(int i=0; i<4; ++i){
            index += s[i] - base[i];
        }
        cout << index << endl;


        vector<string> res;
        string path;
        dfs(res, path, 0);

        auto cmp = [](string &a, string &b){


        };
        sort(res.begin(), res.end());
        for (int i = 0; i < 100; ++i) {
            cout << res[i] << ", " << i << endl;
        }



    }

    return 0;
}

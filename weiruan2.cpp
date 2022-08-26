// task 1
// 最长偶子串



#include <vector>
#include <algorithm>
#include <iostream>




#include <cmath>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int solution(string &S) {
    int n = S.size();
    int res = 0;
    int status = 0;
    vector<int> label(26, INT_MIN);  // 每个字符对应的比特位
    int count=0;  // 记录字符个数
    for (const auto &c: S) {
        if(label[c-'a'] == INT_MIN){
            label[c-'a'] = count;
            count ++;
        }
    }
    vector<int> pos(pow(2, count), -1); // 共有2的count次方种状态
    pos[0] = 0;
    for (int i = 0; i < n; ++i) {
        status ^= 1<< label[S[i]-'a'];
        if (~pos[status]) {
            res = max(res, i + 1 - pos[status]);
        } else {
            pos[status] = i + 1;
        }
    }
    return res;
}



// class Solution {
// public:
//     int findTheLongestSubstring(string s, string t) {
//         int ans = 0, status = 0, n = s.length();
//         vector<int> label(26, INT_MIN);  // 每个字符对应的比特位
//         int count=0;
//         for (const auto &c: t) {
//             if(label[c-'a'] == INT_MIN){
//                 label[c-'a'] = count;
//                 count ++;
//             }
//         }
//         vector<int> pos(1 << count, -1);
//         pos[0] = 0;
//         for (int i = 0; i < n; ++i) {
//             status ^= 1<< label[s[i]-'a'];
//             if (~pos[status]) {
//                 ans = max(ans, i + 1 - pos[status]);
//             } else {
//                 pos[status] = i + 1;
//             }
//         }
//         return ans;
//     }
// };




int main() {
    string s1 = "eleetminicoworoep";  // 13
    string s2 = "leetcodeisgreat"; // 5
    string s3 = "bcbcbc"; // 6

    string ss1 = "bdaaadadb"; //6
    string ss2 = "abacb";  // 0
    string ss3 = "zthtzh";  // 6

    // auto solution = Solution();
    // auto res = solution.findTheLongestSubstring(ss3, "zth");
    // cout << res << endl;

    auto res = solution(ss3);
    cout << res << endl;


    return 0;
}

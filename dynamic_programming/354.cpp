// 354. 俄罗斯套娃信封问题
// 动态规划



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;



class Solution {
public:

    int dp(const vector<vector<int>> &envelopes, int x){
        if(x==0) return 1;
        int m = INT_MIN;
        for (int i = 0; i < x - 1; ++i) {
            if(envelopes[i][1] <= envelopes[x][1]){
                m = max(m, dp(envelopes, i) + 1);
            }
        }
        return m == INT_MIN ? 1 : m;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 按照w升序，按照降序排序
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        int m = INT_MIN;
        for (int i = 0; i < envelopes.size(); ++i) {
            // m = max(m, dp(envelopes, i));
            cout << dp(envelopes, i) << endl;
        }
        return m;

    }
};


int main() {
    
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    auto solution = Solution();
    auto res = solution.maxEnvelopes(envelopes);
    cout << res << endl;

    return 0;
}

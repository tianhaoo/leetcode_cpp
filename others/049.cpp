// 49. 字母异位词分组
// 考验怎么给字符串hash, 可以把26个字母的出现次数作为哈希值

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

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto s:strs){
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto item:m){
            res.push_back(item.second);
        }
        return res;
    }
};


int main() {

    vector<string>  strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto solution = Solution();
    auto res = solution.groupAnagrams(strs);
    printMatrix<string>(res);

    return 0;
}

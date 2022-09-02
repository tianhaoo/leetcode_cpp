// 756. 金字塔转换矩阵
// dfs bfs



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "utils.h"
#include <windows.h>

using namespace std;



class Solution {
public:
    vector<string> getCandidated(string &bottom, unordered_map<string, string> &allowedMap){
        // 先生成所有候选字符
        int n = bottom.size();
        vector<string> candidates(n-1);  // 长度为n-1，第i个位置是满足条件的所有字符
        for(int i=0; i<n-1; ++i){
            string key;
            key.push_back(bottom[i]);
            key.push_back(bottom[i+1]);
            candidates[i]+=allowedMap[key];
        }
        return candidates;
    }

    void backtrack(vector<string> &res, string &path, vector<string> &candidates, int start){
        if (start >  candidates.size()){
            return;
        }
        if(start == candidates.size()){
            res.push_back(path);
            return;
        }
        for(char c: candidates[start]){
            path.push_back(c);
            backtrack(res, path, candidates, start+1);
            path.pop_back();
        }
    }

    vector<string> getUp(string &bottom, unordered_map<string, string> &allowedMap){
        // 根据bottom生成上一层所有可能的组合
        if(bottom.size() == 1){
            vector<string> up;
            return up;
        }
        vector<string> candidates = getCandidated(bottom, allowedMap);
        vector<string> up; // 每个string的长度为n-1；size()是所有可能的up个数。
        string path = "";
        backtrack(up, path, candidates, 0);
        return up;
    }


    bool check(string &bottom, string &up, unordered_map<string, string> &allowedMap){
        // 返回上面这一层是否是合法的
        for(int i=0; i<bottom.size()-1; ++i){
            string key;
            key.push_back(bottom[i]);
            key.push_back(bottom[i+1]);
            if(allowedMap.count(key)==0 || allowedMap[key].find(up[i]) == string::npos){
                return false;
            }
        }
        return true;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, string> allowedMap;
        for(auto allow : allowed){
            allowedMap[allow.substr(0, 2)] += allow.substr(2,1);
        }
        queue<string> q;
        q.push(bottom);
        while(!q.empty()){
            string b = q.front();
            q.pop();
            vector<string> uLst = getUp(b, allowedMap);
            for(string u : uLst){
                if(check(b, u, allowedMap)){
                    q.push(u);
                }
                if(u.length() == 1){
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {

    // string bottom = "AAAA";
    // vector<string> allowed = {"AAC", "AAB", "BCD", "BBE", "DEF"};
    // string bottom = "BCD";
    // vector<string> allowed = {"BCC", "CDE", "CEA"};
    // string bottom = "CCC";
    // vector<string> allowed = {"CBB","ACB","ABD","CDB","BDC","CBC","DBA","DBB","CAB","BCB","BCC","BAA","CCD","BDD","DDD","CCA","CAA","CCC","CCB"};

    string bottom = "BBDCDA";
    vector<string> allowed = {"CAB","ACB","ACA","AAA","AAC","AAB","CDB","BCA","CBB","BCC","BAB","BAC","BAA","CCD","CAA","CCA","CCC","CCB","DAD","DAA","DAC","ACD","DCB","DCC","DCA","CAD","ACC","ABA","ABB","ABD","BBD","BBB","BBA","ADD","ADB","ADC","DDC","DDB","DDA","DDD","CDD","CBC","CBA","CDA","CBD","CDC","DBC","DBD","BDA"};

    auto solution = Solution();


    auto mt = MyTimer();
    auto res = solution.pyramidTransition(bottom, allowed);
    // cout << res << endl;



    return 0;
}

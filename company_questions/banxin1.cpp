//
// Created by Tiana on 2022/10/24.
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


struct Point {
	int x;
	int y;
	Point(int xx, int yy) : x(xx), y(yy) {}
};

class Solution {
public:

    queue<vector<vector<int>>> partition(int n){
        queue<vector<vector<int>>> q;
        vector<int> v;
        v.push_back(1);
        vector<vector<int>> vv;
        vv.push_back(v);

        q.push(vv);
        for (int i = 2; i <= n; ++i) {
            int len = q.size();
            while(len--){
                vector<vector<int>> vv = q.front();
                q.pop();
                for (int j = 0; j < vv.size(); ++j) {
                    vector<vector<int>> t = vv;
                    t[j].push_back(i);
                    q.push(t);
                }
            }
            vector<int> v;
            v.push_back(i);
            vv.push_back(v);
            q.push(vv);
        }
        return q;

    }

    bool check(vector<vector<int>>& lst, vector<Point>& constraints){
        for(auto group: lst){
            if(group.size()>=2){
                if(!check_group(group, constraints)){
                    return false;
                }
            }
        }
        return true;
    }

    bool check_group(vector<int> &group, vector<Point>& constraints){
        for(auto ps : constraints){
            if(!check_in_group(group, ps.x, ps.y)){
                return false;
            }
        }
        return true;
    }

    bool check_in_group(vector<int> &lst, int a, int b){
        bool ain=false, bin=false;
        for(int x: lst){
            if(a==x){
                ain= true;
            }
            if(b==x){
                bin = true;
            }
        }
        return !(ain && bin);
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param N int整型 节点总数
     * @param constraints Point类vector 约束边
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > grouping(int N, vector<Point>& constraints) {
        int min_size = INT_MAX;
        vector<vector<int>> min_res;
        auto q = partition(N);
        while(!q.empty()){
            auto res = q.front();
            q.pop();

            if(check(res, constraints)){
                printMatrix(res);
                if(res.size() < min_size){
                    min_size = res.size();
                    min_res = res;
                }
            }
        }
        return min_res;
    }
};


int main() {
    int n = 1;
    vector<Point> constraints = {
            {1,2},
            {1,3},
            {2, 3}
    };
    auto solution = Solution();
    auto res = solution.grouping(n, constraints);

    cout << "^^^^^^^^^^^^^" << endl;
    printMatrix(res);

    return 0;
}

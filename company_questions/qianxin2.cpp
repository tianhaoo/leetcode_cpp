//
// Created by Tiana on 2022/9/15.
//



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
#include <sstream>

using namespace std;





class Solution {
public:
    vector<int> getNext(vector<vector<int>> &grid, int i, int j){
        int m = INT_MAX;
        int row=0, col=0;
        for (int k = 0; k < 100; ++k) {
            for (int l = 0; l < 100; ++l) {
                if(grid[k][l] == 1){
                    int d = distance(i, j, k, l);
                    if(d < m){
                        m = d;
                        row = k;
                        col = l;
                    }
                }
            }
        }
        return {row, col, m};
    }


    int distance(int ax, int ay, int bx, int by){
        return abs(ax - bx) + abs(by - ay);
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 得到最短路径长度
     * @param points int整型vector<vector<>> 食物位置
     * @return int整型
     */
    int getMinLen(vector<vector<int> >& points) {
        // write code here
        vector<vector<int>> grid(100, vector<int>(100, 0));
        for (int i = 0; i < points.size(); ++i) {
            grid[points[i][0]][points[i][1]] = 1;
        }

        int dis=0;
        int i=0, j=0;
        while(true){
            auto res = getNext(grid, i, j);
            if(res[2] == INT_MAX){
                break;
            }
            grid[i][j] = 0;
            dis += res[2];
            i = res[0];
            j = res[1];
        }
        return dis;

    }
};


int main() {

    vector<vector<int> > points = {{0,5},{1,1}};

    auto solution = Solution();
    auto res = solution.getMinLen(points);
    cout << res << endl;

    return 0;
}

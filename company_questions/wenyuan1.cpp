// 矩形的公共面积



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


void draw(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2, int x1_clap, int y1_clap, int x2_clap, int y2_clap){
    int row_start=max(y1, y1_clap);
    int row_end=min(y2, y2_clap);
    int col_start=max(x1, x1_clap);
    int col_end=min(x2, x2_clap);
    for (int i = row_start; i < row_end; ++i) {
        for (int j = col_start; j < col_end; ++j) {
            matrix[i][j] ++;
        }
    }
}


int main() {
    int n;
    while (cin >> n){
        vector<int> x1(n), y1(n), x2(n), y2(n);
        int x1_min=INT_MAX, y1_min=INT_MAX, x2_max=INT_MIN, y2_max=INT_MIN;
        for (int i = 0; i < n; ++i) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
            if(x1[i] < x1_min){
                x1_min = x1[i];
            }
            if(y1[i] < y1_min){
                y1_min = y1[i];
            }
            if(x2[i] > x2_max){
                x2_max = x2[i];
            }
            if(y2[i] > y2_max){
                y2_max = y2[i];
            }
        }
        vector<vector<int>> m(y2_max-y1_min, vector<int>(x2_max-x1_min, 0));
        int x1_clap=0, y1_clap=0, x2_clap=x2_max-x1_min, y2_clap=y2_max-y1_min;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int x1_current=x1[i]-x1_min, y1_current=y1[i]-y1_min, x2_current=x2[i]-x1_min, y2_current=y2[i]-y1_min;
            if(x1_current >x2_clap || y1_current >y2_clap || x2_current<x1_clap || y2_current <y1_clap){
                // 无重叠区域
                cout << 0 << endl;
                ok= false;
                break;
            }
            if(x1_current>x1_clap || y1_current>y1_clap || x2_current<x2_clap || y2_current<y2_clap){
                // 缩小重叠区域
                x1_clap = x1_current;
                y1_clap = y1_current;
                x2_clap = x2_current;
                y2_clap = y2_current;
            }

            draw(m, x1_current, y1_current, x2_current, y2_current, x1_clap, y1_clap, x2_clap, y2_clap);

        }

        if(ok){
            int count = 0;
            for (int i = y1_clap; i < y2_clap; ++i) {
                for (int j = x1_clap; j < x2_clap; ++j) {
                    if(m[i][j] == n){
                        count++;
                    }
                }
            }
            cout << count << endl;
        }

    }

    return 0;
}

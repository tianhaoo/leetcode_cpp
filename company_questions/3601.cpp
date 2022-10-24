// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 将长N*M厘米的矩形区域划分成N行M列（每行每列的宽度均为1厘米），在第i行第j列的位置上叠放Ai,j个边长为1厘米的正方体（1≤Ai,j≤100），所有正方体就组成了一个立体图形，每个正方体六个面中的一部分会被其它正方体遮挡，未被遮挡的部分的总面积即为该立体图形的表面积，那么该立体图形的表面积是多少平方厘米？
//
// 样例解释：
//
//
//
//
//
// 输入描述
// 第一行包含两个整数N和M，1≤N，M≤1000。
//
// 接下来N行，每行包含M个整数，第i行的第j个整数表示Ai,j。
//
// 输出描述
// 输出表面积的大小。
//
//
// 样例输入
// 2 2
// 2 1
// 1 1
// 样例输出
// 20



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

void put(vector<vector<int>> &grid, int i, int j, int &count, int n, int m){

    count += 6;

    if(grid[i][j] >= 1){
        count -=2;
    }
    int nextI, nextJ;
    nextI = i+1;
    nextJ = j;
    if(nextI>=0 && nextI <=n-1 && nextJ >=0 && nextJ<=m-1 && grid[nextI][nextJ]>grid[i][j]){
        count -=2;
    }
    nextI = i;
    nextJ = j+1;
    if(nextI>=0 && nextI <=n-1 && nextJ >=0 && nextJ<=m-1 && grid[nextI][nextJ]>grid[i][j]){
        count -=2;
    }
    nextI = i-1;
    nextJ = j;
    if(nextI>=0 && nextI <=n-1 && nextJ >=0 && nextJ<=m-1 && grid[nextI][nextJ]>grid[i][j]){
        count -=2;
    }
    nextI = i;
    nextJ = j-1;
    if(nextI>=0 && nextI <=n-1 && nextJ >=0 && nextJ<=m-1 && grid[nextI][nextJ]>grid[i][j]){
        count -=2;
    }

    grid[i][j] ++;

}


int main() {
    int n, m;
    while (cin >> n >> m){
        int count = 0;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i=0; i<n;i++){
            for (int j = 0; j < m; ++j) {
                int num;
                cin >> num;
                for (int k = 0; k < num; ++k) {
                    put(grid, i, j, count, n, m);
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}

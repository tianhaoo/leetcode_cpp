// 48. 旋转图像
// 右旋
// 对于矩阵中第 i 行的第 j 个元素，在旋转后，它出现在倒数第 i 列的第 j行。


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
    pair<int, int> rotateRight(int i, int j, int n){
        return make_pair(j, n-i-1);
    }

    pair<int, int> rotateLeft(int i, int j, int n){
        return make_pair(n-j-1, i);
    }

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int n=int(matrix.size());

        int stop1, stop2;
        if(n%2==0){
            stop1 = n/2;
            stop2 = n/2;
        }else{
            stop1 = n/2+1;
            stop2 = n/2;
        }
        for(int i=0; i<stop1; i++){
            for(int j=0; j<stop2; j++){
                auto next = rotateRight(i, j, n);
                int temp=matrix[i][j];
                while (true){
                    if (next.first==i && next.second==j){
                        swap(temp, matrix[next.first][next.second]);
                        break;
                    }
                    swap(temp, matrix[next.first][next.second]);
                    next = rotateRight(next.first, next.second, n);

                }
            }
        }
    }
};


int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    auto solution = Solution();
    solution.rotate(matrix);
    printMatrix(matrix);

    return 0;
}

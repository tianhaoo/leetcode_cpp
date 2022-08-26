// 微软笔试热身题
// 寻找矩阵平衡点 类似接雨水

#include <vector>
#include <string>
#include "utils.h"

using namespace std;



int solution(vector< vector<int> > &A) {
    int n=A.size(), m=A[0].size();
    vector<int> row_sum(n);
    vector<int> up_sum(n);
    vector<int> down_sum(n);
    vector<int> col_sum(m);
    vector<int> left_sum(m);
    vector<int> right_sum(m);

    int sum;


    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < m; ++j) {
            sum+=A[i][j];
        }
        row_sum[i] = sum;
    }

    for (int j = 0; j < m; ++j) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum+=A[i][j];
        }
        col_sum[j] = sum;
    }


    for (int target_row = 0; target_row < n; ++target_row) {
        sum = 0;
        for (int row = 0; row < target_row; ++row) {
            sum += row_sum[row];
        }
        up_sum[target_row] = sum;
        sum = 0;
        for (int row = target_row+1; row < n ; ++row) {
            sum += row_sum[row];
        }
        down_sum[target_row] = sum;
    }

    for (int target_col = 0; target_col < m; ++target_col) {
        sum = 0;
        for (int col = 0; col < target_col; ++col) {
            sum += col_sum[col];
        }
        left_sum[target_col] = sum;
        sum = 0;
        for (int col = target_col+1; col < m; ++col) {
            sum += col_sum[col];
        }
        right_sum[target_col] = sum;
    }

    int count = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(up_sum[i] == down_sum[i] && left_sum[j] == right_sum[j]){
                count ++ ;
            }
        }
    }

    return count;
}



int main() {

    vector<vector<int>> A = {
            {2, 7, 5},
            {3, 1, 1},
            {2, 1, -7},
            {0, 2, 1},
            {1, 6, 8}
    };

    int res = solution(A);
    cout << res << endl;

    return 0;
}

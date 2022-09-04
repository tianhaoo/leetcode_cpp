// task3
// 使得被排除在外的整数最小



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"




#include <set>
#include <climits>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    set<int> taken, left;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        taken.insert(max(A[i], B[i]));
        left.insert(min(A[i], B[i]));
    }

    int res = INT_MIN;
    for (auto it = left.begin(); it != left.end(); ++it) {
        // 如果taken里面没有的话
        if(taken.find(*it) == taken.end()){
            res = *it;
            break;
        }
    }
    if(res!=INT_MIN){
        return res;
    }else{
        return *left.rbegin() + 1;
    }
}


int main() {

    vector<int> A = {1, 3, 4, 3};
    vector<int> B = {1, 3, 2, 3};

    int res = solution(A, B);
    cout << res << endl;

    return 0;
}

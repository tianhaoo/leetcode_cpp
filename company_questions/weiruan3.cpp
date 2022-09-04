// task2
// 最大对齐子集




#include <iostream>

#include <string>
#include <algorithm>
#include "../utils.h"


#include <vector>
#include <algorithm>
using namespace std;


struct Num{
    int n;
    int index;
    int count;
    Num(int _n, int _index, int _count){
        n = _n;
        index = _index;
        count = _count;
    }
};


int solution(vector<int> &A, int M) {
    vector<Num> lst;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i) {
        if(lst.empty()){
            lst.emplace_back(A[i], i, 1);
        }else{
            if(A[i] == lst.rbegin()->n){
                // 有重复元素
                lst.rbegin()->count ++;
            }else{
                lst.emplace_back(A[i], i, 1);
            }
        }
    }
    int max_elem = lst.rbegin()->n;
    for (const auto &item: lst) {
        for (int i = 0; i < max_elem; i+=M) {

        }
    }



}



int main() {

    int M1 = 3;
    vector<int> A1 = {-3, -2, 1, 0, 8, 7, 1};

    int M2 = 8;
    vector<int> A2 = {7, 1, 11, 8, 4, 10};

    int res = solution(A1, M1);
    cout << res << endl;

    return 0;
}

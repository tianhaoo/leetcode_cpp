//
// Created by Tiana on 2022/9/1.
//





#include <string>
#include <algorithm>
#include "../utils.h"


#include <cmath>
#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;


bool isPrime(int x) {
    for(int y=2; y<=sqrt(x); y++) {
        if (x % y == 0)
            return false;
    }
    return true;
}


int main() {
    int t, n;
    cin >> t;
    for(int tt=0; tt<t; ++tt){
        cin >> n;
        vector<int> lst;
        for(int i=2; i<sqrt(n); ++i){
            if(isPrime(i)){
                lst.push_back(i);
            }
        }
        int count = 0;
        unordered_set<int> nums;
        // 从lst里任取3个，可以重复
        for(int i=0; i<lst.size(); ++i){
            for (int j = 0; j < lst.size(); ++j) {
                for (int k = 0; k < lst.size(); ++k) {
                    int number = pow(lst[i], 2) + pow(lst[j], 3) + pow(lst[k], 4);
                    if(number <= n && number>0){
                        nums.insert(number);
                    }
                }
            }
        }
        cout << nums.size() << endl;
        vector<int> numbers;
        for (const auto &item: nums) {
            numbers.push_back(item);
        }
        sort(numbers.begin(), numbers.end());
        printVector(numbers);


    }
}


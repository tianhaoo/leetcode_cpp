//
// Created by Tiana on 2022/8/4.
//
#include "utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

    vector<int> list = {3, 5, 6, 8, 9, 5, 4, 1, 0, 7};
    printVector(list);

    sort(list.begin(), list.end(), [list](int x, int y){return x * list.size() - y * list.size();});
    printVector(list);


    string s = "hello world";
    cout << s.substr(1, 5) << endl;


    return 0;
}
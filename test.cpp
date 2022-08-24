// 网易游戏雷火 第一题
#include<iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;




int main(){

    vector<vector<int>> lst = {
            {1, 2, 3},
            {1, 2, 3},
            {1},
            {1, 2, 3},
            {4,4,4,4,4,4,4,4,4,4,9}
    };
    printAdjList(lst);




    return 0;
}
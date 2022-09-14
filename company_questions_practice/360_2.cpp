// A和B两个人在抽奖。现在有一个抽奖箱，里面有n张中奖票，m张不中奖票。A和B轮流从中抽一张奖票出来。如果有人抽到中奖票就结束，抽到中奖票的人胜利。抽过的奖票会被丢弃。
//
// 额外的，B每次抽后，会再次抽取一张票并丢弃掉（这张票中奖不算B胜利）。
//
// 现在，A先抽，请问A的胜率，保留4位小数后输出。
//
// 如果两人到最后也没有抽到中奖票算作B胜利。



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
#include <random>
#include <iomanip>

using namespace std;


// a的胜率
double chou(int zhong, int buzhong){
    if(zhong <= 0){
        return 0;
    }
    if(buzhong <= 0){
        return 1;
    }
    if(zhong == 1 && buzhong == 1){
        return 0.5;
    }

    // 这一轮抽到奖券
    double p1 = double(zhong)/(zhong+buzhong);
    // 这一轮没抽到, 下一轮获胜了
    double p2 = double(buzhong)/(zhong+buzhong) * chou(zhong, buzhong-1);
}

int main() {
    int n, m;
    while(cin >> n >> m){
        cout << fixed << setprecision(4) << chou(1, 2) << endl;
    }

    return 0;
}

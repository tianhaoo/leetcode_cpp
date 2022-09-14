// 快到编程竞赛了，小美决定找朋友一起训练，小美拉了一份题单，共有n道题，而且题目难度都差不多，小美目前平均一小时写x道题，而小美的朋友平均一小时写y道题
// （即小美写一题需要1/x小时，小美的朋友写一题需要1/y小时）。小美按1、2、…、n的顺序写题，而她的朋友按n、n-1、…、1的顺序写题。她们决定了赢的规则：
// 谁先写完编号为k的题，谁就获得胜利。那么，假设两人按不变的速度写题，且每写完一题立刻去写下一题，小美能获胜吗？
// 3
// 5 3 3 3
// 5 3 3 2
// 5 3 3 4

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

using namespace std;


int main() {
    int t;
    while (cin >> t){
        int n, x, y, k;
        for (int i = 0; i < t; ++i) {
            cin >> n >> x >> y >> k;
            double mei = k/double(x);
            double peng = (n-k+1)/double(y);
            if(mei < peng){
                cout << "Win" << endl;
            }else if(mei > peng){
                cout << "Lose" << endl;
            }else{
                cout << "Tie" << endl;
            }
        }
    }

    return 0;
}

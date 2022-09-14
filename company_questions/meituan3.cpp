// 某天小美进入了一个迷宫探险，根据地图所示，这个迷宫里有无数个房间，序号分别为1、2、3、…、∞，入口房间的序号为1，
// 任意序号为正整数x的房间都与序号2*x和2*x+1的房间之间各有一条路径，但是这些路径是单向的，即只能从序号为x的房间去到序号为2*x或2*x+1的房间，
// 而不能从序号为2*x或2*x+1的房间去到序号为x的房间。在任何时刻小美都可以选择结束探险并离开迷宫，但是离开之后将无法再次进入迷宫。
// 小美还提前了解了迷宫中宝藏的信息，已知宝藏共有n个，其中第 i 个宝藏在序号为pi的房间，价值为wi，且一个房间中可能有多个宝藏。
// 小美为了得到更多的宝藏，需要精心规划路线，她找到你帮忙，想请你帮她计算一下，能获得的宝藏价值和最大值为多少。



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
#include <iomanip>
#include <random>

using namespace std;


// 搜索最大价值的路径
void backtrack(unordered_map<int, int> &roomValue, int maxRoom, int &maxValue, int curValue, int curRoom){
    if(curRoom > maxRoom){
        maxValue = max(maxValue, curValue);
        return;
    }
    for (int nextRoom : {2*curRoom, 2*curRoom+1}) {
        curValue += roomValue[nextRoom];
        backtrack(roomValue, maxRoom, maxValue, curValue, nextRoom);
        curValue -= roomValue[nextRoom];
    }
}


int main() {
    int n;  // 宝藏数量
    while (cin >> n){
        vector<int> loc(n+1), values(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> loc[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> values[i];
        }
        unordered_map<int, int> roomValue;
        int maxRoom=INT_MIN;
        for (int i = 1; i <= n; ++i) {
            int bao=i, room=loc[bao], value=values[bao];
            maxRoom = max(maxRoom, room);
            roomValue[room] += value;
        }
        int maxValue = 0;
        backtrack(roomValue, maxRoom, maxValue, 0, 1);
        cout << maxValue << endl;


    }

    return 0;
}

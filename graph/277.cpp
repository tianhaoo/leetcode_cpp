// 277. 搜寻名人
// 图



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;

vector<vector<int>> graph = {
    {1,1,0},
    {0,1,0},
    {1,1,1}
};


bool knows(int a, int b){
    return graph[a][b];
};

class Solution {
public:
    int findCelebrity(int n) {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        while(q.size() >= 2){ // 队列只剩一个人的时候停止，也有可能一个人都不剩了
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            bool aKnowsB = knows(a, b);
            bool bKnowsA = knows(b, a);
            if(aKnowsB && !bKnowsA){
                q.push(b);
            }else if(!aKnowsB && bKnowsA){
                q.push(a);
            }else if(aKnowsB && bKnowsA){

            }else if(!aKnowsB && !bKnowsA){

            }
        }
        if(q.empty()){
            return -1;
        }
        int lastOne = q.front();
        for (int i = 0; i < n; ++i) {
            if(i==lastOne) continue;
            if(!knows(i, lastOne) || knows(lastOne, i)){
                // 如果有人不知道lastOne 或者 lastone知道别人
                return -1;
            }
        }
        return lastOne;
    }
};


int main() {
    auto solution = Solution();
    auto res = solution.findCelebrity(3);
    cout << res << endl;

    return 0;
}

// 给出一棵树，编号为1~n，点有权值(有小于0的)
// 你可以做以下操作：
// 选择树的一棵子树，但是这棵子树必须包含节点1，你可以把这棵子树的所有节点的权值都加1或者都减1
// 问：至少需要多少个操作，才可以把所有点权都变为0
// 输入：
// 3
// 1 2
// 1 3
// 1 -1 -1
//
//



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
#include <random>
#include "../utils.h"

using namespace std;


int main() {
    int n;
    while (cin >> n){

        vector<vector<int>> graph(n, vector<int>());
        int ai, bi;
        for(int i=0; i<n-1; ++i){
            cin >> ai >> bi;
            graph[ai-1].push_back(bi-1);
            graph[bi-1].push_back(ai-1);
        }
        int value;
        vector<int> valueList(n);  // 记录每个图节点的值
        for(int i=0; i<n; ++i){
            cin >> value;
            valueList[i] = value;
        }


        }
    }

    return 0;
}

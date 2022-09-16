// 给定一棵树，每个节点会被染上一种颜色，共三种可能的颜色，现在要割掉一条边，使两个子连通图每种颜色的节点都至少有一个，问有多少种割法
// n<1e5



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


int main() {

    string s = "[3,9,20,null,null,15,7]";

    auto root = deserializeTree(s);
    printTree(root);

    return 0;
}

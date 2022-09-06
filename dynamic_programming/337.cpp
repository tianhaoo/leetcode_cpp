// 337. 打家劫舍 III
// 动态规划



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



// 返回[root, ....]能偷到的最大值
int dp(TreeNode *root, unordered_map<TreeNode*, int> &memo){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        int res = root->val;
        return res;
    }
    if(memo.count(root)){
        return memo[root];
    }

    // 偷root
    int p1 = root->val;
    if(root->left != nullptr){
        p1 += dp(root->left->left, memo);
        p1 += dp(root->left->right, memo);
    }
    if(root->right != nullptr){
        p1 += dp(root->right->left, memo);
        p1 += dp(root->right->right, memo);
    }

    // 不偷root
    int p2 = dp(root->left, memo) + dp(root->right, memo);

    int res = max(p1, p2);
    memo[root] = res;
    return  res;

}


class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return dp(root, memo);

    }
};


int main() {
    // string s = "[3,2,3,null,3,null,1]";
    string s = "[3,4,5,1,3,null,1]";
    TreeNode* root = deserializeTree(s);
    printTree(root);
    auto solution = Solution();
    auto res = solution.rob(root);
    cout << res << endl;



    return 0;
}

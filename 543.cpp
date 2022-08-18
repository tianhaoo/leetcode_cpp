// 543. 二叉树的直径
// 二叉树

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;


class Solution {
    int max_d = INT_MIN;
public:
    int traverse(TreeNode *root){
        if (root == nullptr){
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        max_d = max(left+right, max_d);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root== nullptr){
            return 0;
        }else{
            traverse(root);
            return max_d;
        }

    }
};


int main() {

    auto root = deserializeTree("[1, 2, 3, 4, 5]");
    printTree(root);
    auto solution = Solution();
    auto res = solution.diameterOfBinaryTree(root);
    cout << res << endl;


    return 0;
}

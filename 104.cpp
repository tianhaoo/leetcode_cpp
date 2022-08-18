// 104. 二叉树的最大深度
// 待解决

#include "utils.h"
#include <iostream>
#include <vector>
#include <climits>

#define null INT_MAX

using namespace std;



class Solution {
    int depth=0, max_depth=INT_MIN;
public:
//    void traverse(TreeNode *root){
//        if (root != nullptr){
//            depth ++;
//            if(root->left == nullptr && root->right == nullptr){
//                max_depth = max(max_depth, depth);
//            }
//            traverse(root->left);
//            traverse(root->right);
//            depth --;
//        }
//    }
//
//    int maxDepth(TreeNode* root) {
//        if (root != nullptr){
//            traverse(root);
//            return max_depth;
//        }else{
//            return 0;
//        }
//
//    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;


    }
};


int main(){
    string s = "[3,9,20,null,null,15,7]";

    auto root = deserializeTree(s);
    printTree(root);

    auto solution = Solution();
    int res = solution.maxDepth(root);
    cout << res << endl;

}
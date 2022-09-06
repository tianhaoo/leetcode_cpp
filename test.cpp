#include"utils.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

auto cmp = [](TreeNode *a, TreeNode *b){
    return a->val < b->val;
};


void traverse(TreeNode *root, int parent, unordered_map<TreeNode*, int> &memo){
    if(root != nullptr){
        cout << root->val << ", " << parent << endl;
        memo[root] = parent;
        traverse(root->left, root->val, memo);
        traverse(root->right, root->val, memo);
    }
}


void printMap(unordered_map<TreeNode*, int> m){
    for (const auto &item: m) {
        cout << item.first << ", " << item.second << endl;
    }
}


int main(){
    string s = "[3,2,3,null,3,null,1]";
    TreeNode* root = deserializeTree(s);

    printTree(root);


    unordered_map<TreeNode*, int> memo;  // 存储每个二叉树节点的父节点
    traverse(root, INT_MAX, memo);

    printMap(memo);


    return 0;
}
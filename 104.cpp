// 104. 二叉树的最大深度
// 待解决

#include "utils.h"
#include <iostream>
#include <vector>
#include <climits>

#define null INT_MAX

using namespace std;



class Solution {
public:
    int maxDepth(TreeNode* root) {
        return 0;

    }
};


int main(){
    vector<int> lst = {3,9,20,null,null,15,7};

    printVector(lst);

    auto root = deserializeTree(lst);
    printTree(root);

    preOrder(root);


}
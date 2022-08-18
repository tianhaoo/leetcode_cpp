// 515. 在每个树行中找最大值
// 二叉树 层序遍历


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include "utils.h"

using namespace std;


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> lst;  // 记录结果
        if(root == nullptr){
            return lst;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto sz = q.size();
            int min_value = INT_MIN;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                min_value = max(min_value, node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            lst.push_back(min_value);
        }
        return lst;
    }
};


int main() {

    auto root = deserializeTree("[1,3,2,5,3,null,9]");
    printTree(root);

    auto solution = Solution();
    auto res = solution.largestValues(root);
    printVector(res);

    return 0;
}

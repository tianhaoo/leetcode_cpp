// 101. 对称二叉树


#include "../utils.h"


#include <cstdio>
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
#include <list>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;


class Solution {
    bool check(vector<int> &nums){
        if(nums.size() <= 1){
            return true;
        }
        int left=0, right=nums.size()-1;
        while(left < right){
            if(nums[left] != nums[right]){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> res;
            for(int i=0; i<sz; ++i){
                TreeNode* p = q.front();
                q.pop();
                if(p==nullptr) {
                    res.push_back(INT_MIN);
                    continue;
                }else{
                    res.push_back(p->val);
                    if(p->left != nullptr){
                        q.push(p->left);
                    }else{
                        q.push(nullptr);
                    }
                    if(p->right != nullptr){
                        q.push(p->right);
                    }else{
                        q.push(nullptr);
                    }
                }

            }
            if(!check(res)) return false;
        }
        return true;
    }
};


int main() {
    TreeNode *root = deserializeTree("[1,2,2,null,3,null,3]");
    auto solution = Solution();
    auto res = solution.isSymmetric(root);
    cout << res << endl;


    return 0;
}

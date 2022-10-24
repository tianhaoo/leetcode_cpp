//
// Created by Tiana on 2022/10/16.
//



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


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a ListNode类
     * @param b ListNode类
     * @return ListNode类
     */
    ListNode* xorList(ListNode* a, ListNode* b) {
        // write code here
        ListNode* p;
        vector<int> lst_a, lst_b;
        p = a;
        while(p!=nullptr){
            lst_a.push_back(p->val);
            p = p->next;
        }
        p = b;
        while(p!=nullptr){
            lst_b.push_back(p->val);
            p = p->next;
        }

        reverse(lst_a.begin(), lst_a.end());


        if(lst_a.size() < lst_b.size()){
            int diff = lst_b.size() - lst_a.size();
            for (int i = 0; i < diff; ++i) {
                lst_a.push_back(0);
            }
        }else{
            int diff = lst_a.size() - lst_b.size();
            for (int i = 0; i < diff; ++i) {
                lst_b.push_back(0);
            }
        }

        vector<int> res(lst_a.size());
        for (int i = 0; i < lst_a.size(); ++i) {
            res[i] = lst_a[i] ^ lst_b[i];
        }

        ListNode *dummy = new ListNode(0);
        p = dummy;
        bool flag = true;
        for (int i = 0; i < res.size(); ++i) {
            if(flag && res[i] == 0) continue;
            p->next = new ListNode(res[i]);
            p = p->next;
            flag = false;
        }


        return dummy->next;


    }
};


int main() {
    auto solution = Solution();
    auto a = deserializeLinkedList({1,1,1});
    auto b = deserializeLinkedList({1,0, 1});

    auto res = solution.xorList(a, b);
    auto r = serializeLinkedList(res);
    printVector(r);

    return 0;
}

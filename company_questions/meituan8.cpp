// 小团有n个球，编号为1到n。有一天，这n个球掉进了两个魔法筒里面。每个魔法筒可以视为一个栈，即按顺序掉进去的球只能以逆序取出来。魔法筒上面附有的魔法使得小团每次只能从桶的顶端拿走当前仍在两个桶中的所有球中编号最小的球，或者将顶端的球放入另一个魔法筒。现在小团想知道他至少要操作多少次才能将所有球都从桶中取出。每次操作即从桶中拿出一个球或将一个球从一个桶的顶端移入另一个桶。
//
//
//
// 输入描述
// 第一行有三个正整数n,x,y(2<=n<=1000,1<=x,y<=n-1,x+y=n)，分别代表球的总数，第一个桶中的球数和第二个桶中的球数。
//
// 第二行有x个数，依次代表第一个桶中从底端到顶端的x个球。
//
// 第三行有y个数，依次代表第二个桶中从底端到顶端的y个球。
//
// 保证编号为1到n的每个球均恰好在一个桶中出现。
//
// 输出描述
// 输出一个非负整数，代表所求的答案。
// 样例输入
// 5 2 3
// 3 4
// 2 5 1
// 样例输出
// 8


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


vector<int> findMin(const vector<int> &s1, const vector<int> &s2){
    int m = INT_MAX;
    int pos = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if(m>s1[i]){
            m=s1[i];
            pos = 1;
        }
    }
    for (int i = 0; i < s2.size(); ++i) {
        if(m>s2[i]){
            m=s2[i];
            pos = 2;
        }
    }
    return {m, pos};
}


int takeMin(vector<int> &s1, vector<int> &s2, int m, int pos){
    if(pos == 1){
        int caozuo = 0;
        int index = s1.size()-1;
        while (s1[index] != m){
            s2.push_back(s1[index]);
            s1.pop_back();
            index--;
            caozuo++;
        }
        s1.pop_back();
        caozuo ++;
        return caozuo;
    }
    if(pos == 2){
        int caozuo = 0;
        int index = s2.size()-1;
        while (s2[index] != m){
            s1.push_back(s2[index]);
            s2.pop_back();
            index--;
            caozuo++;
        }
        s2.pop_back();
        caozuo ++;
        return caozuo;
    }

}

int main() {
    int n,x,y;
    while(cin >>n >> x>> y){
        vector<int> s1(x), s2(y);
        for (int i = 0; i < x; ++i) {
            cin >> s1[i];
        }
        for (int i = 0; i < y; ++i) {
            cin >> s2[i];
        }

        int sum = 0;
        while(!s1.empty() || !s2.empty()){
            auto res = findMin(s1, s2);
            int count = takeMin(s1, s2, res[0], res[1]);
            sum += count;
        }
        cout << sum << endl;



    }

    return 0;
}

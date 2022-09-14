//某天，小美在调试她的神经网络模型，这个模型共有n个参数，目前这些参数分别为a1、a2、…、an，为了让参数看起来更加随机而且增加训练效果，
// 她需要调节参数使所有参数满足a1+a2+…+an≠0且a1*a2*…*an≠0，她每次可以选择一个参数ai并将其变为ai+1，小美请你帮她计算一下，
// 最少需要几次操作才能使参数达到她的要求。




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
#include <random>

using namespace std;


int main() {
    int n;
    while (cin >> n){
        vector<int> lst(n);
        int temp;
        int count0=0, sum=0;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            if(temp == 0){
                count0 ++;
            }
            sum += temp;
            lst.push_back(temp);
        }
        if(count0 == 0 && sum != 0){
            cout << 0 << endl;
        }
        int ans=0;
        if(sum + count0 == 0){
            ans = count0 + 1;
        } else{
            ans = count0;
        }
        cout << ans << endl;
    }

    return 0;
}

// 有一种特殊的DNA，仅仅由核酸A和T组成，长度为n，顺次连接
//
// 科学家有一种新的手段，可以改变这种DNA。每一次，科学家可以交换该DNA上两个核酸的位置，也可以将某个特定位置的核酸修改为另一种核酸。
//
// 现在有一个DNA，科学家希望将其改造成另一种DNA，希望你计算最少的操作次数。

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
    string from, to;
    while (cin >> from >> to){
        int countA=0, countT=0;
        for (int i = 0; i < from.size(); ++i) {
            if(from[i] != to[i]){
                if(from[i] == 'A') countA++;
                if(from[i] == 'T') countT++;
            }
        }
        cout << max(countA, countT) << endl;
    }
    return 0;
}

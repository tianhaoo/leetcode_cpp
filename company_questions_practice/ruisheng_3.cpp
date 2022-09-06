// n的阶乘末尾含0的个数



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
#include <random>
#include "../utils.h"

using namespace std;


int count5(int x){
    int count = 0;
    while(x != 0){
        if(x % 5 == 0) count++;
        x /= 5;
    }
    return count;
}

int countZero(int n){
    int count =0;
    for(int i=1; i<=n; ++i){
        count += count5(i);
    }
    return count;
}


int main() {

    cout << countZero(20) << endl;

    return 0;
}

//

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



#include <iostream>
using namespace std;


int main() {

    int n;
    while (cin >> n){
        if(n<=3){
            cout << 1 << endl;
            continue;
        }
        int pre1=1, pre2=1, pre3=1;
        int temp1, temp2, temp3;
        for(int i=1; i<=n-3; ++i){
            if(pre3 >= 1000000007){
                pre3 = pre3%1000000007;
            }else{
                temp1 = pre1;
                temp2 = pre2;
                temp3 = pre3;
                pre3 = 1 + temp1 + temp2 + temp3;
                pre2 = temp3;
                pre1 = temp2;
            }

        }
        cout << pre3 << endl;
    }



    return 0;
}

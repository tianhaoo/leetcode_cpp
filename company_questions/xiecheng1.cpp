//



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


int main() {
    int n, k;
    while (cin >> n >> k){
        int count = 0;
        if(k%2 == 0){
            count = (k+2) * (k + 2) / 4;
        }else{
            k --;
            count = (k+2) * (k + 2) / 4;
            count += (k+1 + 2)/2;
        }
        cout << fixed << setprecision(2) << 1.0*n*n / count << endl;
    }

    return 0;
}

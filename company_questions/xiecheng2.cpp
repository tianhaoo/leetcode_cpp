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
    int t;
    while (cin >> t){
        for (int i = 0; i < t; ++i) {
            int a0Count=0, b0Count=0;
            vector<int> a(4), b(4);
            for (int j = 0; j < 4; ++j) {
                cin >> a[j];
                if(a[j] == 0) a0Count++;
            }
            for (int j = 0; j < 4; ++j) {
                cin >> b[j];
                if(b[j] == 0) b0Count++;
            }
            if(a0Count !=b0Count){
                cout << -1 << endl;
            }else{
                int diff=0;
                for (int j = 0; j < a.size(); ++j) {
                    if(a[j] != b[j]){
                        diff++;
                    }
                }
                if(diff == 0){
                    cout << 0 << endl;
                }else if(diff == 1 || diff == 3){
                    cout << -1 << endl;
                }else if(diff == 4){
                    cout << 2 << endl;
                }else if(diff == 2){
                    if(a[0] != b[0] && a[3] != b[3]){
                        cout << 2 << endl;
                    }else if(a[1] != b[1] && a[2] != b[2]){
                        cout << 2 << endl;
                    }else{
                        cout << 1 << endl;
                    }
                }else{
                    cout << -1 << endl;
                }

            }
        }
    }

    return 0;
}

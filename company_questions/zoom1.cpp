//
// Created by Tiana on 2022/10/10.
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


int main() {
    long long a, b, n;
    while(cin >> a >> b){
        cin >> n;
        if(a > b){
            for (int i = 0; i < n; ++i) {
                char op;
                long long temp;
                cin >> op;
                cin >> temp;

                if(temp >= 0){
                    if(op == '+'){
                        a += temp;
                    }else{
                        b -= temp;
                    }
                }else{
                    if(op == '+'){
                        b += temp;
                    }else{
                        a -= temp;
                    }
                }

            }
        }else{
            for (int i = 0; i < n; ++i) {

                char op;
                long long temp;
                cin >> op;
                cin >> temp;


                if(temp >= 0){
                    if(op == '+'){
                        b += temp;
                    }else{
                        a -= temp;
                    }
                }else{
                    if(op == '+'){
                        a += temp;
                    }else{
                        b -= temp;
                    }
                }
            }
        }

        cout << a << ' ' << b << endl;
    }
    return 0;
}

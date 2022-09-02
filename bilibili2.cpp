//
// Created by Tiana on 2022/9/1.
//




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;


int main() {
    int n;
    vector<long long> lst;
    int Q;
    vector<long long> caozuos;
    int temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        lst.push_back(temp);
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> temp;
        caozuos.push_back(temp);
    }

    long long sum;
    for (const auto &caozuo: caozuos) {
        sum=0;
        for (auto &number: lst) {
            number += caozuo;
            sum += abs(number);
        }
        cout << sum << endl;
    }

    return 0;
}

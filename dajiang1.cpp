//
// Created by peiwen on 2022/8/7.
//
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int n, m;
    double start,sum;
    while (cin >> n >> m){
        sum = 0;
        start = n;
        for(int i=0; i<m; i++){
            sum += start;
            start = sqrt(start);
        }
        cout << fixed << setprecision(2) <<  sum << endl;
    }

    return 0;
}
//
// Created by Tiana on 2022/8/5.
//


#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

int sum_nx(int x, int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        string s(i, x+'0');
        sum += atoi(s.c_str());
    }
    return sum;
}


int main(){
    cout << sum_nx(1, 2) << endl;

    return 0;
}
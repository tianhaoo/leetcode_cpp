//
// Created by peiwen on 2022/8/7.
//
#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

bool isShuiXianHua(int n){
    int temp_n, number, sum;
    sum = 0;
    temp_n = n;
    while (temp_n != 0){
        number = temp_n % 10;
        sum += (int)pow(number, 3);
        temp_n /= 10;
    }
    return sum == n;

}

int main(){
    int m, n;
    vector<int> list;
    while (cin >> m >> n){
        for(int i=m; i<=n; i++){
            if(isShuiXianHua(i))
                list.push_back(i);
        }
        if (list.empty()){
            cout << "no"  << endl;
        }else{
            for(int i=0; i<list.size(); i++){
                cout << list[i];
                if (i < list.size()-1)
                    cout << ' ';
            }
            cout << endl;
        }
        list.clear();
    }
    return 0;
}
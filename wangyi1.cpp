// 网易游戏雷火 第一题
#include<iostream>
#include <vector>

using namespace std;

bool validElement(int n){
    if (n == 32){
        return true;
    }else if (n >= 65 && n <= 90){
        return true;
    }else{
        return false;
    }
}

bool validVector(const vector<int>& lst, int X){
    for (int elem: lst){
        if (! validElement(elem-X)){
            return false;
        }
    }
    return true;
}

int main(){
    int N;

    while(cin >> N){
        vector<int> lst;
        int temp, X_ans, sum;
        for(int i=0; i<N; i++){
            cin >> temp;
            lst.push_back(temp);
        }
        sum = 0;
        for (int X=0; X<=999; X++){
            if (validVector(lst, X)){
                X_ans = X;
                sum ++;
            }
        }
        if (sum==1){
            for(int elem: lst){
                cout << (char)(elem - X_ans);
            }
            cout << endl;
        }else{
            cout << sum << endl;
        }
    }
    return 0;
}
//
// Created by Tiana on 2022/9/15.
// 30,60,5,7
// 18,20,6,8
// 43



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
#include <sstream>

using namespace std;


int sumA(vector<int> &lst){
    int sum = 0;
    for (int i = 0; i < lst.size(); ++i) {
        sum += lst[i];
    }
    if(lst.size() >= 3){
        sum = int(sum * 0.6);
    }
    return sum;
}

int sumB(vector<int> lst){
    sort(lst.begin(), lst.end());
    int index = lst.size() - 1;
    int sum = 0;
    while(index>=0 && index-1>=0 && index-2>=0){
        sum += lst[index] + lst[index-1] + lst[index-2] - min(min(lst[index], lst[index-1]), lst[index-2]);
        index -= 3;
    }
    while(index>=0){
        sum += lst[index];
        index --;
    }
    return sum;
}

void backtrack(vector<int> &choiceA, vector<int> &choiceB, vector<int> &lstA, vector<int> &lstB, int n, int cur, int &m){
    if(cur >= n){
        cout << endl;
        printVector(choiceA);
        printVector(choiceB);
        cout << endl;

        int a = sumA(choiceA);
        int b = sumB(choiceB);
        m = min(m, a+b);
        return;
    }




    choiceA.push_back(lstA[cur]);
    backtrack(choiceA, choiceB, lstA, lstB, n, cur+1, m);
    choiceA.pop_back();

    choiceB.push_back(lstB[cur]);
    backtrack(choiceA, choiceB, lstA, lstB, n, cur+1, m);
    choiceB.pop_back();

}




int main() {
    string input;
    getline(cin, input);
    istringstream ss1(input);
    string temp;
    vector<int> lstA, lstB;
    while(getline(ss1, temp, ',')){
        lstA.push_back(stoi(temp));
    }
    getline(cin, input);
    istringstream ss2(input);
    while(getline(ss2, temp, ',')){
        lstB.push_back(stoi(temp));
    }

    if(lstA.size()==1){
        cout << min(lstA[0], lstB[0]) << endl;
    }else if(lstA.size()==2){
        cout << min(lstA[0], lstB[0]) + min(lstA[1], lstB[1]) << endl;
    // }
    // else if(lstA.size()==3){
    //     int p1 = int((lstA[0] + lstA[1] + lstA[2])*0.6);
    //     int p2 = lstB[0] + lstB[1] + lstB[2] - min(min(lstB[0], lstB[1]), lstB[2]);
    //     int p3 = min(lstA[0], lstB[0]) + min(lstA[1] + lstB[1]) + min(lstA[2], lstB[2]);
    //     cout << min(min(p1, p2), p3) << endl;
    }else{
        int sum=0;
        vector<int> choiceA, choiceB;
        int m = INT_MAX;



        backtrack(choiceA, choiceB, lstA, lstB, lstA.size(), 0, m);
        cout << m << endl;
    }


    return 0;
}

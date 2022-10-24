// 多线程相关问题
// 多线程按顺序打印1234



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
#include<condition_variable>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
condition_variable cv;

int num=10;
int cur = 0;

void print(int n){
    for (int i = 0; i < num; ++i) {
        unique_lock<mutex> lock(m);
        while(cur != n){
            cv.wait(lock);
        }
        cout << n << endl;
        cur = (cur+1) % 3;
        cv.notify_all();
    }

}


int main() {
    thread t1(print, 0);
    thread t2(print, 1);
    thread t3(print, 2);

    t1.join();
    t2.join();
    t3.join();


    return 0;
}

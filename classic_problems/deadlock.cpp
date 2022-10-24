// 写一个死锁

// 死锁的四个条件
// 1. 互斥
// 2. 占有并等待
// 3. 循环等待
// 4. 不可剥夺


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
#include<thread>
#include<mutex>
#include <unistd.h>

using namespace std;


int data = 2;  // 全局变量
mutex m1, m2;

void f1(){
    m1.lock();
    sleep(1);

    data = data * data;

    cout << "f1 is wating for m2" << endl;
    m2.lock();
    cout << "f1: " << data << endl;
    m2.unlock();

    m1.unlock();
}

void f2(){
    m2.lock();
    sleep(1);

    data = data * data;

    cout << "f2 is waiting for m1" << endl;
    m1.lock();
    cout << "f2: " << data << endl;
    m1.unlock();

    m2.unlock();
}



int main() {
    thread t1(f1);
    thread t2(f2);

    sleep(1);

    t1.join();
    t2.join();
    cout << "main end" << endl;

    return 0;
}

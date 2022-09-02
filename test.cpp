#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include "utils.h"
using namespace std;





bool isPrime(int x) {
    for(int y=2; y<=sqrt(x); y++) {
        if (x % y == 0)
            return false;
    }
    return true;
}


int main() {

    vector<int> lst;
    for(int i=2; i<1000000; ++i){
        if(isPrime(i)){
            lst.push_back(i);
        }
    }
    printVector(lst);


    return 0;
}
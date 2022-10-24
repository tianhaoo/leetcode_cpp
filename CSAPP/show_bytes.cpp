// 打印变量的字节
// 验证是大端序还是小端序



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

void show_bytes(unsigned char *start, int len){
    for (int i = 0; i < len; ++i) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}




int main() {
    // int
    int x = 1;
    show_bytes((unsigned char*) &x, sizeof(int));

    //float
    float y = 1.0;
    show_bytes((unsigned char *) &y, sizeof(float ));

    // pointer
    void *z;
    show_bytes((unsigned char *) &z, sizeof(void *));
    cout << z << endl;

    const char *s = "123456";
    show_bytes((unsigned char *) s, sizeof(s));


    return 0;
}

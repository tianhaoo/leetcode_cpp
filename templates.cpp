// 一些代码模板



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;


// debug递归函数
#define TIAN 1
#if (TIAN > 0)
#define DECLARE_PRINT \
    int count_ = 0; \
    void printIndent(int n) { \
        for (int i = 0; i < n; i++) { \
            cout << "   "; \
        } \
    }
#define PRINT_PARAM(p1, p2) \
    printIndent(count_++); \
    cout \
    << "p1 = " << p1 << ", " \
    << "p2 = " << p2 << ", " \
    << endl;
#define PRINT_RES(res) \
    printIndent(--count_); \
    cout \
    << "return " << res \
    << endl;
#else
#define  DECLARE_PRINT
#define PRINT_PARAM(p1, p2)
#define PRINT_RES(res)
#endif



int main() {



    return 0;
}

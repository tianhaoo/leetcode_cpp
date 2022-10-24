// 判断质数




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
#include <random>
#include "../utils.h"

using namespace std;

// 常规遍历法
// 遍历 [2..sqrt(n)]
// 时间复杂度O(n^0.5)
int isPrime(int n) {
    if (n<=1) return false;
    if (n==2) return true;

    for(int i=2;i<=sqrt(n)+1;i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

// 埃氏筛法
// 这是一个我感觉和辗转相除法一样NB的算法。原理也很简单。
// 首先将2到n范围内的整数写下来。其中2是最小的素数。将表中所有的2的倍数划去,
// 表中剩下的最小的数字就是3，他不能被更小的数整除，所以3是素数。
// 再将表中所有的3的倍数划去…… 以此类推，如果表中剩余的最小的数是m，那么m就是素数。
// 然后将表中所有m的倍数划去，像这样反复操作，就能依次枚举n以内的素数,
// 埃氏筛法的时间复杂度是0(n*log(log n))。
vector<bool> primes(int n) {
    // 返回 [0, ... n],每个数是否是质数
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2;i<=n;i++){ // 从2开始往后筛
        if (isPrime[i]){
            for (int j = i+i; j <= n; j+=i) {
                // 找到一个质数之后就把他后面所有的1,2,3倍的数置为false
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// 欧拉线性筛  欧拉筛、线性筛
// 想要快速地筛出一定上限内的素数？
// 下面这种方法可以保证范围内的每个合数都被删掉（在 bool 数组里面标记为非素数），而且任一合数只被：
// “最小质因数 × 最大因数（非自己） = 这个合数”
// 的途径删掉。由于每个数只被筛一次，时间复杂度为 O(n)。


vector<bool> primes2(int n)//筛到n
{
    vector<bool> isPrime(n+1, true);
    vector<int> primes(n+1, 0);
    int cnt = 0;

    //以“每个数都是素数”为初始状态，逐个删去
    isPrime[0] = false;
    isPrime[1] = false;//1不是素数

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]){ //没筛掉
            primes[++cnt] = i;
        }
        for(int j = 1; j <= cnt && i*primes[j] <= n/*不超上限*/; j++) {
            //从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
            isPrime[ i*primes[j] ] = false;

            if(i % primes[j] == 0)//i中也含有Prime[j]这个因子
                break; //重要步骤。见原理
        }
    }
    return isPrime;
}

int main() {
    
    int n = 1000000;
    auto p2 = primes(n);
    auto p3 = primes2(n);
    for (int i = 0; i < n; ++i) {
        bool r1 = isPrime(i);
        bool r2 = p2[i];
        bool r3 = p3[i];
        if(r1 != r2 || r2 != r3 || r1 != r3){
            cout << i << ", " << r1 << ", " << r2 << ", " << r3 <<endl;
        }
    }
    cout << "all correct" << endl;

    return 0;
}

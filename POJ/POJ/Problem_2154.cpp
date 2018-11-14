#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <time.h>
#include <vector>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <complex>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

int MOD;
int n;

inline int __add__(int a, const int b)
{
    a += b;
    return a < MOD ? a : a - MOD;
}

inline int __mul__(long long a, const int b)
{
    a *= b;
    return (int) (a < MOD ? a : a - a / MOD * MOD);
}

inline int __pow__(int x, int n)
{
    int r = 1;
    for (; n; n >>= 1, x = __mul__(x, x)) if (n & 1) r = __mul__(r, x);
    return r;
}

namespace euler_sieve
{
    typedef int TYPE;
    const TYPE MAXN = 100050;
    TYPE prime[MAXN];
    int cnt = 0;
    bool vis[MAXN];
    void euler_sieve()
    {
        vis[0] = vis[1] = true;
        for (TYPE i = 2; i < MAXN; i++)
        {
            if (!vis[i]) prime[cnt++] = i;
            for (TYPE j = 0; j < cnt, i * prime[j] < MAXN; j++)
            {
                vis[i * prime[j]] = true;
                if (i % prime[j] == 0) break;
            }
        }
    }
}
using euler_sieve::prime;

int phi(int x)
{
    int res = x;
    for (int i = 0; prime[i] * prime[i] <= x; ++i)
    {
        if (x % prime[i] == 0){
            res = res / prime[i] * (prime[i] - 1);
            while (x % prime[i] == 0) x /= prime[i];
        }
    }
    if (x > 1) res = res / x * (x - 1);
    return res % MOD;
}

int main()
{
    euler_sieve::euler_sieve();
    int t;
    int res;
    for (scanf("%d\n", &t); t--; )
    {
        res = 0;
        scanf("%d%d", &n, &MOD);
        for (int i = 1; i * i <= n; ++i)
        {
            if (i * i == n) res = __add__(res, __mul__(phi(i), __pow__(n, i - 1)));
            else if (n % i == 0) res = __add__(res, __add__(__mul__(phi(n / i), __pow__(n, i - 1)), __mul__(phi(i), __pow__(n, n / i - 1))));
        }
        printf("%d\n", res);
    }
    return 0;
}

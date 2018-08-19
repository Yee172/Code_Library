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

const int MAXN = 31623;
int prime[MAXN], cnt;
bool vis[MAXN];

inline int __mul__(long long a, const int b, int MOD) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
inline int __pow__(int a, long long b, int MOD) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a, MOD)) { if (b & 1) r = __mul__(r, a, MOD); } return r; }

inline bool is_prime(int n)
{
    for (int i = 0; i < cnt, prime[i] * prime[i] <= n; ++i) if (n % prime[i] == 0) return false;
    return true;
}

int main()
{
    for (int i = 2; i < MAXN; ++i)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt, i * prime[j] < MAXN; ++j)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    int p, a;
    while (~ scanf("%d%d", &p, &a) && (p || a))
    {
        if (__pow__(a, p, p) == a && !is_prime(p)) puts("yes");
        else puts("no");
    }
    return 0;
}

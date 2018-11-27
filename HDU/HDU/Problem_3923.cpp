#include <bits/stdc++.h>
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

const int MOD = 0x3b9aca07;

inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
inline int __pow__(int a, int b)
{
    int r = 1;
    for (; b; b >>= 1)
    {
        if (b & 1) r = __mul__(r, a);
        a = __mul__(a, a);
    }
    return r;
}
inline int __inv__(const int a) { return __pow__(a, MOD - 2); }

int main()
{
    int t, cas, n, m, res;
    for (scanf("%d", &t), cas = 1; t--; ++cas)
    {
        scanf("%d%d", &n, &m);
        res = 0;
        for (int i = 0; i < m; ++i)
            res = __add__(res, __pow__(n, __gcd(i, m)));
        if (m & 1) res = __add__(res, __mul__(m, __pow__(n, (m >> 1) + 1)));
        else res = __add__(res, __mul__(m >> 1, __add__(__pow__(n, (m >> 1) + 1), __pow__(n, m >> 1))));
        printf("Case #%d: %d\n", cas, __mul__(res, __inv__(m << 1)));
    }
    return 0;
}

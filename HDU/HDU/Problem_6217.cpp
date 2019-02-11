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

typedef long double db;

int MOD;
inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
inline int __pow__(int a, long long b, const int mod) { MOD = mod; int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) if (b & 1) r = __mul__(r, a); return r; }

db ONE = 1.0;

db S_j(int d, int j)
{
    db res = 0;
    for (int k = 0; k <= d; ++k)
    {
        int mod = k << 3 | j;
        res += (db) __pow__(16, d - k, mod) / mod;
    }
    for (int k = 1; k < 10; ++k)
    {
        res += ONE / ((1ll << (k << 2)) * (k + d << 3 | j));
    }
    return res - floor(res);
}

int digit_pi(int d)
{
    --d;
    db res = 3;
    res += S_j(d, 1) * 4 - S_j(d, 4) * 2 - S_j(d, 5) - S_j(d, 6);
    return (int) ((res - floor(res)) * 16);
}

int main()
{
    int t, n, cas = 1;
    for (scanf("%d", &t); t--; ++cas)
    {
        scanf("%d", &n);
        printf("Case #%d: %d %X\n", cas, n, digit_pi(n));
    }
    return 0;
}

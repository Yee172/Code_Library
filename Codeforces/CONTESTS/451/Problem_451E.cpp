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

namespace fast_mod_operation
{
    inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
    inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
    inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
    inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) if (b & 1) r = __mul__(r, a); return r; }
    inline int __mod__(const long long a, const int b) { return (int) (a < b ? a : a - a / b * b); }
    inline int __mod__(const long long a) { return (int) (a < MOD ? a : a - a / MOD * MOD); }
}
using fast_mod_operation::__add__;
using fast_mod_operation::__sub__;
using fast_mod_operation::__mul__;
using fast_mod_operation::__pow__;
using fast_mod_operation::__mod__;

const int MAXN = 30;
ll f[MAXN];
int n, fn, r;
bool pm;
ll s, p;

inline int g(ll k)
{
    int res = fn;
    for (int i = 0; i < n - 1; ++i) res = __mul__(res, __mod__(n + k - 1 - i));
    return res;
}

int main()
{
    fn = 1;
    scanf("%d%lld", &n, &s);
    rep(i, n) scanf("%lld", f + i);
    for (int i = 1; i < n; ++i) fn = __mul__(fn, i);
    fn = __pow__(fn, MOD - 2);
    r = 0;
    for (int i = (1 << n) - 1; i >= 0; --i)
    {
        p = 0;
        pm = true;
        rep(j, n) if (i & (1 << j)) p += f[j] + 1, pm ^= true;
        if (p <= s) r = pm ? __add__(r, g(s - p)) : __sub__(r, g(s - p));
    }
    printf("%d\n", r);
    return 0;
}

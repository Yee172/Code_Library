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

const int MAXN = 200005;
const int MOD = 0x3b800001;

namespace fast_mod_operation
{
    inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
    inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
    inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
    inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) { if (b & 1) r = __mul__(r, a); } return r; }
    inline int __mod__(const long long a, const int b) { return (int) (a < b ? a : a - a / b * b); }
    inline int __mod__(const int a) { return a < MOD ? (a < 0 ? a + MOD : a) : a - a / MOD * MOD; }
}

using namespace fast_mod_operation;

int factorial[MAXN];
int mod_inverse[MAXN];
int factorial_inverse[MAXN];
inline void initialize()
{
    mod_inverse[0] = 0, factorial[0] = factorial_inverse[0] = mod_inverse[1] = 1;
    for (int i = 1; i < MAXN; i++)
        factorial[i] = __mul__(factorial[i - 1], i);
    for (int i = 2; i < MAXN; i++)
        mod_inverse[i] = __mul__((MOD - MOD / i), mod_inverse[MOD % i]);
    for (int i = 1; i < MAXN; i++)
        factorial_inverse[i] = __mul__(factorial_inverse[i - 1], mod_inverse[i]);
}

inline int binomial(int n, int k)
{ return n < k ? 0 : __mul__(factorial[n], __mul__(factorial_inverse[n - k], factorial_inverse[k])); }

void Main()
{
    initialize();
    int t, n, m, k, res;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d%d", &n, &m, &k);
        res = 0;
        rep(i, k / n + 1) res = __add__(res, __mod__((i & 1 ? -1 : 1) * __mul__(binomial(k - i * n + m - 1, m - 1), binomial(m, i))));
        printf("%d\n", res);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

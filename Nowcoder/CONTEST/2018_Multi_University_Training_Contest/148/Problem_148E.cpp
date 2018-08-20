#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

const int MOD = 0x3b800001;

namespace fast_mod_operation
{
    inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
    inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
    inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
    inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) if (b & 1) r = __mul__(r, a); return r; }
    inline int __mod__(const long long a, const int b) { return (int) (a < b ? a : a - a / b * b); }
    inline int __mod__(const int a) { return a < MOD ? (a < 0 ? a - a / MOD * MOD + MOD : a) : a - a / MOD * MOD; }
}
using fast_mod_operation::__add__;
using fast_mod_operation::__sub__;
using fast_mod_operation::__mul__;
using fast_mod_operation::__pow__;
using fast_mod_operation::__mod__;

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))
#define clear(a) memset(a, 0, sizeof a)

const int MAXN = 100050;

namespace euler_function_sieve
{
    typedef int TYPE;
    vector<TYPE> prime;
    bool vis[MAXN];
    TYPE phi[MAXN];
    void euler_function_sieve()
    {
        phi[0] = 0, phi[1] = 1;
        for (TYPE i = 2; i < MAXN; i++)
        {
            if (!vis[i]) prime.push_back(i), phi[i] = i - 1;
            for (TYPE j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
            {
                vis[i * prime[j]] = true;
                if (i % prime[j] == 0)
                {
                    phi[i * prime[j]] = phi[i] * prime[j];
                    break;
                }
                else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}
using euler_function_sieve::phi;

int a[MAXN], f[MAXN], tmp, res[MAXN];
int mod_inverse[MAXN];
int maximum;

int main()
{
    euler_function_sieve::euler_function_sieve();
    mod_inverse[0] = 0, mod_inverse[1] = 1;
    for (int i = 2; i < MAXN; ++i) mod_inverse[i] = __mul__(MOD - MOD / i, mod_inverse[__mod__(MOD, i)]);
    int t;
    int n, m, rtn;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &n, &m);
        maximum = 0;
        rtn = 0;
        clear(a);
        clear(f);
        clear(res);
        rep(i, n) scanf("%d", &tmp), ++a[tmp], maximum = maximum > tmp ? maximum : tmp;
        _rep(i, maximum) for (int j = i; j <= maximum; j += i) f[i] += a[j];
        _rep(i, maximum)
            for (int j = i; j <= maximum, j <= m; j += i)
                res[j] = __add__(res[j], __mul__(phi[i], __sub__(__pow__(j + 1, f[i]), 1)));
        _rep(i, m) res[i] = __mul__(res[i], mod_inverse[i]), rtn ^= res[i];
        printf("%d\n", rtn);
    }
    return 0;
}

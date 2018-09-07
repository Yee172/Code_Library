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
    inline int __mod__(const int a) { return a < MOD ? a : a - a / MOD * MOD; }
}

using fast_mod_operation::__add__;
using fast_mod_operation::__sub__;
using fast_mod_operation::__mul__;
using fast_mod_operation::__pow__;
using fast_mod_operation::__mod__;

int dp[1005][1005][3][3];
int a[1005];

int main()
{
    int t, n, s;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &n, &s);
        rep(i, n) scanf("%d", a + i + 1);
        memset(dp, 0, sizeof dp);
        dp[0][0][0][0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= s; ++j)
                rep(k, 3)
                    rep(l, 3)
                    {
                        int tmp = dp[i][j][k][l];
                        if (j + a[i + 1] <= s)
                        {
                            dp[i + 1][j + a[i + 1]][k][l] = __add__(dp[i + 1][j + a[i + 1]][k][l], tmp);
                            if (k + 1 <= 2)
                                dp[i + 1][j + a[i + 1]][k + 1][l] = __add__(dp[i + 1][j + a[i + 1]][k + 1][l], tmp);
                        }
                        if (l + 1 <= 2)
                            dp[i + 1][j][k][l + 1] = __add__(dp[i + 1][j][k][l + 1], tmp);
                        dp[i + 1][j][k][l] = __add__(dp[i + 1][j][k][l], tmp);
                    }
        int res = 0;
        for (int i = 0; i <= s; ++i) res = __add__(res, dp[n][i][2][2]);
        printf("%d\n", __mul__(res, 4));
    }
    return 0;
}

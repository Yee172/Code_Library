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

const int MOD = 10007;
inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
inline int __mod__(const int a) { return a < MOD ? a : a - a / MOD * MOD; }

namespace KMP
{
    const int MAXN = 200050;
    char a[MAXN];
    int len;
    int _next[MAXN];

    inline void get_next()
    {
        _next[0] = 0;
        for (int q = 1, k = 0; q < len; ++q)
        {
            while (k > 0 && a[q] != a[k]) k = _next[k - 1];
            if (a[q] == a[k]) ++k;
            _next[q] = k;
        }
    }
}
using namespace KMP;
int dp[MAXN];

int main()
{
    int t, res;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%s", &len, a);
        get_next();
        dp[0] = 0;
        rep(i, len) if (_next[i]) dp[_next[i]] = dp[_next[_next[i] - 1]] + 1;
        res = __mod__(len);
        rep(i, len) res = __add__(res, dp[_next[i]]);
        printf("%d\n", res);
    }
    return 0;
}

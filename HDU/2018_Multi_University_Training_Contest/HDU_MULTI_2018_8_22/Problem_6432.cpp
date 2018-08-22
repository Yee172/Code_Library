#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

const int MAXN = 100005l;
const int MOD = 0x3b800001;
inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

int dp[MAXN];

int main()
{
    dp[4] = 1, dp[5] = 8, dp[6] = 36;
    for (int i = 7; i < MAXN; ++i) dp[i] = __add__(__mul__(i - 3, dp[i - 1]), __mul__(i - 2, __add__(__mul__(2, dp[i - 2]), dp[i - 3])));
    int t, n;
    for (scanf("%d", &t); t--; ) scanf("%d", &n), printf("%d\n", dp[n]);
    return 0;
}

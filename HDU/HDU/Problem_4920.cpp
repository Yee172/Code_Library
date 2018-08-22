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

const int MOD = 3;
inline int __mod__(const int a) { return a < MOD ? (a < 0 ? a - a / MOD * MOD + MOD : a) : a - a / MOD * MOD; }

const int MAXN = 1000;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

int main()
{
    int n;
    while (~ scanf("%d", &n))
    {
        rep(i, n) rep(j, n) scanf("%d", &a[i][j]), a[i][j] = __mod__(a[i][j]);
        rep(i, n) rep(j, n) scanf("%d", &b[i][j]), b[i][j] = __mod__(b[i][j]);
        rep(i, n) rep(j, n) c[i][j] = 0;
        rep(i, n) rep(k, n) if (a[i][k]) rep(j, n) c[i][j] += a[i][k] * b[k][j];
        rep(i, n) rep(j, n) printf("%d%c", __mod__(c[i][j]), " \n"[j == n - 1]);
    }
    return 0;
}

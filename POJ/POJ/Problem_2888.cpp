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

const int MOD = 9973;
const int MAXN = 100050;
const int MAXM = 12;

inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
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

int A[MAXM][MAXM], B[45][MAXM][MAXM], O[MAXM][MAXM], C[MAXM][MAXM];
int prime[MAXN / 10];
bool vis[MAXN];
int cnt;

inline int phi(int x)
{
    int res = x;
    for (int i = 0; prime[i] * prime[i] <= x; ++i)
        if (x % prime[i] == 0)
        {
            res = res / prime[i] * (prime[i] - 1);
            while (x % prime[i] == 0) x /= prime[i];
        }
    if (x > 1) res = res / x * (x - 1);
    return res < MOD ? res : res - res / MOD * MOD;
}

int t, n, m, k, a, b, res;

inline void __mul__(int A[MAXN][MAXM], int B[MAXN][MAXM])
{
    memset(C, 0, sizeof C);
    for (int k = 1; k <= m; ++k)
        for (int i = 1; i <= m; ++i)
            if (A[i][k])
                for (int j = 1; j <= m; ++j)
                    C[i][j] = __add__(C[i][j], __mul__(A[i][k], B[k][j]));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            A[i][j] = C[i][j];
}

inline int __cal__(int n)
{
    int res = 0;
    memset(A, 0, sizeof A);
    for (int i = 1; i <= m; ++i) A[i][i] = 1;
    memcpy(B, O, sizeof O);
    for (int i = 0; n; n >>= 1, ++i) if (n & 1) __mul__(A, B[i]);
    for (int i = 1; i <= m; ++i) res = __add__(res, A[i][i]);
    return res;
}

int main()
{
    vis[0] = vis[1] = true;
    for (int i = 2; i < MAXN; ++i)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < MAXN; ++j)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    for (scanf("%d", &t); t--; )
    {
        res = 0;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                O[i][j] = 1;
        rep(i, k) scanf("%d%d", &a, &b), O[a][b] = O[b][a] = 0;
        memcpy(A, O, sizeof O);
        memcpy(B[0], A, sizeof A);
        for (int i = 1; (1 << i) <= n; ++i) __mul__(A, A), memcpy(B[i], A, sizeof A);
        for (int i = 1; i * i <= n; ++i)
            if (n % i == 0)
            {
                if (i * i == n) res = __add__(res, __mul__(__cal__(i), phi(i)));
                else res = __add__(res, __add__(__mul__(__cal__(i), phi(n / i)), __mul__(__cal__(n / i), phi(i))));
            }
        res = __mul__(res, __inv__(n));
        printf("%d\n", res);
    }
    return 0;
}

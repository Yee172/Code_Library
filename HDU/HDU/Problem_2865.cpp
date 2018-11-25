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
const int MAXN = 100050;
int n, k;
int prime[MAXN / 10];
bool vis[MAXN];
int cnt;
inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
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

inline int __cal__(const int n)
{
    int res = __pow__(k - 2, n);
    if (n & 1) res = __sub__(res, k - 2);
    else res = __add__(res, k - 2);
    return res;
}

inline int phi(int n)
{
    int res = n;
    for (int i = 0; i * i <= n; ++i)
    {
        if (n % prime[i] == 0)
        {
            res = res / prime[i] * (prime[i] - 1);
            while (n % prime[i] == 0) n /= prime[i];
        }
    }
    if (n > 1) res = res / n * (n - 1);
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
    int res;
    while (~scanf("%d%d", &n, &k))
    {
        res = 0;
        for (int i = 1; i * i <= n; ++i)
            if (n % i == 0)
            {
                if (i * i == n) res = __add__(res, __mul__(__cal__(i), phi(i)));
                else res = __add__(res, __add__(__mul__(__cal__(i), phi(n / i)), __mul__(__cal__(n / i), phi(i))));
            }
        res = __mul__(res, __inv__(n));
        res = __mul__(res, k);
        printf("%d\n", res);
    }
    return 0;
}

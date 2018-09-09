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

const int MOD = 0x1fff;

inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
inline int __mod__(const int a) { return a < MOD ? a : a - a / MOD * MOD; }

int o[2][2], r[2][2], p[2][2];
inline void __mul__(int (&a)[2][2], int (&b)[2][2])
{
    memset(r, 0, sizeof r);
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
            if (a[i][k])
                for (int j = 0; j < 2; ++j)
                    r[i][j] = __add__(r[i][j], __mul__(a[i][k], b[k][j]));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            a[i][j] = r[i][j];
}

int main()
{
    int n, k, x, x2, y;
    while (~scanf("%d%d", &n, &k))
    {
        if (n == 4 || n == 9 || n == 16 || n == 25)
        {
            puts("No answers can meet such conditions");
            continue;
        }
        for (y = 1; ; ++y)
        {
            x2 = 1 + n * y * y;
            x = (int) sqrt(x2);
            if (x * x == x2) break;
        }
        x = __mod__(x);
        y = __mod__(y);
        o[0][0] = o[1][1] = x, o[0][1] = __mul__(n, y), o[1][0] = y;
        p[0][0] = p[1][1] = 1, p[0][1] = p[1][0] = 0;
        for (; k; k >>= 1)
        {
            if (k & 1) __mul__(p, o);
            __mul__(o, o);
        }
        printf("%d\n", p[0][0]);
    }
    return 0;
}

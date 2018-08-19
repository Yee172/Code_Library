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

const int MAXN = 1 << 17;
int a[3][MAXN];
int b[3][MAXN];

namespace fast_io_head
{
    const int __FREAD_BUFFER_SIZE__ = 1 << 20;
    char __BUFFER__[__FREAD_BUFFER_SIZE__], *__P1__=__BUFFER__, *__P2__=__BUFFER__;
#define __IF_END__ (__P1__ == __P2__)
#define __READ_ONE__ (fread(__BUFFER__, 1, __FREAD_BUFFER_SIZE__, stdin))
#define __GET_CHAR__ (__IF_END__ && (__P2__ = (__P1__ = __BUFFER__) + __READ_ONE__, __IF_END__) ? -1 : *__P1__++)
    template <typename T>
    inline bool read(T &x)
    {
        char c;
        bool f = false;
        for (c = __GET_CHAR__; !isdigit(c); c = __GET_CHAR__)
        {
            if (c == EOF) return false;
            if (c == '-') f = true;
        }
        for (x = 0; isdigit(c); c = __GET_CHAR__) x = (x << 1) + (x << 3) + (c ^ 48);
        if (f) x = -x;
        return true;
    }
}
using fast_io_head::read;

namespace FWT
{
    const int MOD = 0x3b800001;
    const int inv2 = MOD + 1 >> 1;

    inline void FWT_OR(int * x, int len, int mode=1)
    {
        for (int step = 1; step < len; step <<= 1)
            for (int d = step << 1, i = 0; i < len; i += d)
                for (int j = i; j < i + step; ++j)
                {
                    int a = x[j], b = x[j + step];
                    if (mode == -1) x[j + step] = (b - a + MOD) % MOD;
                    else x[j + step] = (a + b) % MOD;
                }
    }

    inline void FWT_AND(int * x, int len, int mode=1)
    {
        for (int step = 1; step < len; step <<= 1)
            for (int d = step << 1, i = 0; i < len; i += d)
                for (int j = i; j < i + step; ++j)
                {
                    int a = x[j], b = x[j + step];
                    if (mode == -1) x[j] = (a - b + MOD) % MOD;
                    else x[j] = (a + b) % MOD;
                }
    }

    inline void FWT_XOR(int * x, int len, int mode=1)
    {
        for (int step = 1; step < len; step <<= 1)
            for (int d = step << 1, i = 0; i < len; i += d)
                for (int j = i; j < i + step; ++j)
                {
                    int a = x[j], b = x[j + step];
                    x[j] = (a + b) % MOD;
                    x[j + step] = (a - b + MOD) % MOD;
                    if (mode == -1)
                    {
                        x[j] = (int)(1ll * x[j] * inv2 % MOD);
                        x[j + step] = (int)(1ll * x[j + step] * inv2 % MOD);
                    }
                }
    }
}
using FWT::MOD;
using FWT::FWT_OR;
using FWT::FWT_AND;
using FWT::FWT_XOR;

void Main()
{
    int n;
    read(n);
    n = 1 << n;
    _debug(n);
    rep(i, n) read(a[2][i]), a[0][i] = a[1][i] = a[2][i];
    rep(i, n) read(b[2][i]), b[0][i] = b[1][i] = b[2][i];
    FWT_OR(a[0], n), FWT_AND(a[1], n), FWT_XOR(a[2], n);
    FWT_OR(b[0], n), FWT_AND(b[1], n), FWT_XOR(b[2], n);
    rep(_, 3) rep(i, n) a[_][i] = (int)(1ll * a[_][i] * b[_][i] % MOD);
    FWT_OR(a[0], n, -1), FWT_AND(a[1], n, -1), FWT_XOR(a[2], n, -1);
    rep(_, 3) rep(i, n) printf("%d%c", a[_][i], i == n - 1 ? '\n' : ' ');
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

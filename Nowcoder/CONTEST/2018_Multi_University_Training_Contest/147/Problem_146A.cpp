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

const int MAXN = 1 << 18;
const int MOD = 0x3b9aca07;
int a[MAXN];
int b[MAXN];
inline int powmod(ll a,ll b)
{ll r = 1; a %= MOD; for(; b; b >>= 1) {if (b & 1) r = r * a % MOD; a = a * a % MOD;} return (int)r;}

namespace FWT
{
    const int MOD = 0x3b9aca07;
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
using FWT::FWT_XOR;

void Main()
{
    int n;
    scanf("%d", &n);
    rep(i, n) scanf("%d", a + i);
    rep(i, n) scanf("%d", b + i);
    FWT_XOR(a, n);
    FWT_XOR(b, n);
    rep(i, n) a[i] = (int)(1ll * powmod(a[i], MOD - 2) * b[i] % MOD);
    FWT_XOR(a, n, -1);
    rep(i, n) printf("%d\n", a[i]);
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

namespace fast_io
{
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
    template <typename A, typename B>
    inline bool read(A &a, B&b) { return read(a) && read(b); }
    template <typename A, typename B, typename C>
    inline bool read(A &a, B &b, C &c) { return read(a) && read(b) && read(c); }
}
using fast_io::read;

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

inline long long __mul__(long long a, long long b, long long mod)
{
    a = a - a / mod * mod, b = b - b / mod * mod;
    return ((a * b - ((long long)((long double)a / mod * b + 1e-3) * mod)) % mod + mod) % mod;
}

inline int __pow__(int a, int b, int MOD) { int r = 1; for (; b; b >>= 1, a = (int)(1ll * a * a % MOD)) if (b & 1) r = (int)(1ll * r * a % MOD); return r; }

inline int get_bit(int x) { for (; x != (x & -x); x += x & -x); return x; }

namespace NTT
{
    int MOD = 0x3b9aca07;
    const int g = 3;

    namespace fast_mod_operation
    {
        inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
        inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
        inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
        inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) { if (b & 1) r = __mul__(r, a); } return r; }
    }
    using fast_mod_operation::__add__;
    using fast_mod_operation::__sub__;
    using fast_mod_operation::__mul__;
    using fast_mod_operation::__pow__;

    inline int reverse(int x, int r) { int res = 0; for (int i = 0; i < r; ++i) if (x & (1 << i)) res += 1 << (r - i - 1); return res; }

    void ntt(int * A, int n, int mode=1)
    {
        int r = 0, cnt = 0, t = n;
        for (; t > 1; ++cnt, t >>= 1);
        for (; ; ++r) if ((1 << r) == n) break;
        for (int i = 0; i < n; ++i)
        {
            int tmp = reverse(i, r);
            if (i < tmp) swap(A[i], A[tmp]);
        }
        for (int s = 1; s <= r; ++s)
        {
            int m = 1 << s;
            int p = m >> 1;
            int wn = __pow__(g, (MOD - 1) / m);
            for (int k = 0; k < n; k += m)
            {
                int w = 1;
                for (int j = 0; j < p; ++j)
                {
                    int x = A[k + j], y = __mul__(w, A[k + j + p]);
                    A[k + j] = __add__(x, y);
                    A[k + j + p] = __sub__(x, y);
                    w = __mul__(w, wn);
                }
            }
        }
        if (mode == -1)
        {
            int inv = __pow__(1 << cnt, MOD - 2);
            for (int i = 1; i < n / 2; ++i) swap(A[i], A[n - i]);
            for (int i = 0; i < n; ++i) A[i] = __mul__(A[i], inv);
        }
    }
}
using NTT::__mul__;

const int MAXN = 300010;
const int __mod[] = {469762049, 998244353, 1004535809};
const ll __Mod = 1ll * __mod[0] * __mod[1];
int res[3][MAXN];
int n, m, mod, a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main()
{
    read(n, m, mod);
    rep(i, n + 1) read(a[i]);
    rep(i, m + 1) read(b[i]);
    int fn = get_bit(n + m + 1);
    rep(_, 3)
    {
        memset(c, 0, sizeof c), memset(d, 0, sizeof d);
        copy(a, a + n + 1, c), copy(b, b + m + 1, d);
        NTT::MOD = __mod[_];
        NTT::ntt(c, fn), NTT::ntt(d, fn);
        rep(i, fn + 1) res[_][i] = __mul__(c[i], d[i]);
        NTT::ntt(res[_], fn, -1);
    }
    rep(i, n + m + 1)
    {
        ll A = 0;
        A += __mul__(1ll * res[0][i] * __mod[1] % __Mod, __pow__(__mod[1] % __mod[0], __mod[0] - 2, __mod[0]), __Mod);
        A += __mul__(1ll * res[1][i] * __mod[0] % __Mod, __pow__(__mod[0] % __mod[1], __mod[1] - 2, __mod[1]), __Mod);
        A %= __Mod;
        ll k = (res[2][i] - A) % __mod[2];
        k = k < 0 ? k + __mod[2] : k;
        (k *= __pow__((int)(__Mod % __mod[2]), __mod[2] - 2, __mod[2])) %= __mod[2];
        int res = (int)(((k % mod) * (__Mod % mod) % mod + A % mod) % mod);
        // Using CRT to get res
        printf("%d%c", res, i == n + m ? '\n' : ' ');
    }
    return 0;
}

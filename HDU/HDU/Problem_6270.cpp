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

const int MAXN = 100050;

namespace fast_mod_operation
{
    const int MOD = 0x3b800001;
    inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
    inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
    inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
    inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) if (b & 1) r = __mul__(r, a); return r; }
    inline int __mod__(const long long a, const int b) { return (int) (a < b ? a : a - a / b * b); }
    inline int __mod__(const int a) { return a < MOD ? a : a - a / MOD * MOD; }
}
using fast_mod_operation::MOD;
using fast_mod_operation::__add__;
using fast_mod_operation::__sub__;
using fast_mod_operation::__mul__;
using fast_mod_operation::__pow__;
using fast_mod_operation::__mod__;

int factorial[MAXN];
int mod_inverse[MAXN];
int factorial_inverse[MAXN];

inline void initialize()
{
    factorial[0] = factorial[1] = mod_inverse[1] = factorial_inverse[0] = factorial_inverse[1] = 1;
    mod_inverse[0] = 0;
    for (int i = 2; i < MAXN; ++i)
    {
        factorial[i] = __mul__(factorial[i - 1], i);
        mod_inverse[i] = __mul__(MOD - MOD / i, mod_inverse[MOD - MOD / i * i]);
        factorial_inverse[i] = __mul__(factorial_inverse[i - 1], mod_inverse[i]);
    }
}

inline int binomial(const int n, const int k)
{
    return k > n ? 0 : __mul__(factorial[n], __mul__(factorial_inverse[n - k], factorial_inverse[k]));
}

namespace NTT
{
    const int g = 3;

    inline int get_bit(int x) { for (; x != (x & -x); x += x & -x); return x; }
    inline int reverse(int x, int r) { int res = 0; for (int i = 0; i < r; ++i) if (x & (1 << i)) res += 1 << (r - i - 1); return res; }

    void ntt(vector<int> &A, int n, int mode=1)
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
using NTT::ntt;
using NTT::get_bit;

vector<vector<int> > poly;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > p;
int _bit, _n[3], _i[2], res;

struct family
{
    int a, b, minimum;
    bool operator < (family f) { return minimum < f.minimum; }
}f[MAXN];

int main()
{
    initialize();
    int t, n, pos, sum;
    for (scanf("%d", &t); t--; )
    {
        while (!p.empty()) p.pop();
        scanf("%d", &n);
        poly.assign(n, vector<int>());
        poly.clear();
        sum = 0;
        pos = -1;
        memset(_n, 0, sizeof _n);
        rep(i, n)
        {
            scanf("%d%d", &f[i].a, &f[i].b);
            f[i].minimum = f[i].a < f[i].b ? f[i].a : f[i].b;
            sum += f[i].a;
            if (f[i].minimum)
            {
                p.push(make_pair(f[i].minimum, i));
                poly[i].resize(f[i].minimum + 1);
                poly[i][0] = 1;
                _rep(k, f[i].minimum)
                    poly[i][k] = __mul__(binomial(f[i].a, k), __mul__(binomial(f[i].b, k), factorial[k]));
                pos = i;
                _n[2] = f[i].minimum;
            }
        }

        while (p.size() > 1)
        {
            _n[0] = p.top().first;
            _i[0] = p.top().second;
            p.pop();
            _n[1] = p.top().first;
            _i[1] = p.top().second;
            p.pop();
            _n[2] = _n[0] + _n[1];
            _bit = get_bit(_n[2] + 1);
            poly[_i[0]].resize(_bit, 0);
            poly[_i[1]].resize(_bit, 0);
            ntt(poly[_i[0]], _bit);
            ntt(poly[_i[1]], _bit);
            for (int i = 0; i <= _bit; ++i) poly[_i[0]][i] = __mul__(poly[_i[0]][i], poly[_i[1]][i]);
            ntt(poly[_i[0]], _bit, -1);
            pos = _i[0];
            p.push(make_pair(_n[2], pos));
        }

        res = factorial[sum];
        if (pos == -1)
        {
            printf("%d\n", res);
            continue;
        }
        for (int i = 1; i <= _n[2]; ++i)
        {
            if (poly[pos][i])
            {
                if (i & 1) res = __sub__(res, __mul__(poly[pos][i], factorial[sum - i]));
                else res = __add__(res, __mul__(poly[pos][i], factorial[sum - i]));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

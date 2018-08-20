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
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
#define fi first
#define se second
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

const int MAXN = 100005;
const int MOD = 0x3b800001;

namespace fast_mod_operation
{
    inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }
    inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
    inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
    inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) if (b & 1) r = __mul__(r, a); return r; }
    inline int __mod__(const long long a, const int b) { return (int) (a < b ? a : a - a / b * b); }
    inline int __mod__(const int a) { return a < MOD ? a : a - a / MOD * MOD; }
}
using fast_mod_operation::__add__;
using fast_mod_operation::__sub__;
using fast_mod_operation::__mul__;
using fast_mod_operation::__pow__;
using fast_mod_operation::__mod__;

int factorial[MAXN << 1];
int mod_inverse[MAXN];
int factorial_inverse[MAXN];
vector<piii> a;
int level;

inline void init()
{
    mod_inverse[0] = 0, factorial[0] = mod_inverse[1] = factorial_inverse[0] = 1;
    for (int i = 1; i < MAXN << 1; ++i) factorial[i] = __mul__(factorial[i - 1], i);
    for (int i = 2; i < MAXN; ++i) mod_inverse[i] = __mul__(MOD - MOD / i, mod_inverse[__mod__(MOD, i)]);
    for (int i = 1; i < MAXN; ++i) factorial_inverse[i] = __mul__(factorial_inverse[i - 1], mod_inverse[i]);
}

inline int get_sum(int place)
{
    if (place == 0) return 0;
    int res = 0;
    for (auto p : a)
    {
        int l = p.fi.fi;
        int x = p.fi.se;
        int v = p.se;
        if (place >= x) { res = __add__(res, __mul__(v, __mul__(__mul__(factorial[level - l + place - x], factorial_inverse[level - l]), factorial_inverse[place - x]))); }
    }
    return res;
}

int main()
{
    init();
    int t, n, m, op, l, r, w;
    for (scanf("%d", &t); t--; )
    {
        level = 0;
        a.resize(0);
        scanf("%d%d", &n, &m);
        rep(i, m)
        {
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d%d", &l, &r, &w);
                a.push_back(make_pair(make_pair(level - 1, l), __mod__(w)));
                if (r + 1 <= n) a.push_back(make_pair(make_pair(level - 1, r + 1), __mod__(2 * MOD - w)));
            }
            else if (op == 2) ++level;
            else
            {
                scanf("%d%d", &l, &r);
                printf("%d\n", __sub__(get_sum(r), get_sum(l - 1)));
            }
        }
    }
    return 0;
}

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
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (ll (i) = 1; (i) <= (n); ++(i))

namespace Chinese_remainder_theorem
{
    inline long long __mul__(long long a, long long b, long long mod)
    {
        a = a - a / mod * mod, b = b - b / mod * mod;
        return ((a * b - ((long long)((long double)a / mod * b + 1e-3) * mod)) % mod + mod) % mod;
    }

    void extend_gcd(long long a, long long b, long long &d, long long &x, long long &y)
    {
        if (!b) { d = a; x = 1; y = 0; }
        else { extend_gcd(b, a % b, d, y, x); y -= x * (a / b); }
    }

    long long CRT(const int n, const long long a[], const long long r[])
    {
        long long m2, r2, d, x, y, c, t;
        long long m1 = a[0];
        long long r1 = r[0];
        bool no_solution = false;
        for (int i = 1; i < n; ++i)
        {
            m2 = a[i];
            r2 = r[i];
            extend_gcd(m1, m2, d, x, y);
            c = r2 - r1;
            if (c % d)
            {
                no_solution = true;
                break;
            }
            t = m2 / d;
            x = __mul__(c / d, x % t, t);
            r1 += m1 * x;
            m1 = m1 / d * m2;
        }
        if (no_solution) return -1;
        if (n == 1 && r1 == 0) return m1;
        return r1;
    }
}
using Chinese_remainder_theorem::CRT;

const int MAXN = 100050;
ll a[MAXN], b[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    rep(i, n) scanf("%lld%lld", a + i, b + i);
    printf("%lld\n", CRT(n, a, b));
    return 0;
}

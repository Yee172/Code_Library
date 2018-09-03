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

void extend_gcd(int a, int b, int &d, int &x, int &y)
{
    if (!b) { d = a; x = 1; y = 0; }
    else { extend_gcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int chinese_remainder(const int n, const int a[], const int r[])
{
    int m2, r2, i, d, x, y, c, t;
    int m1 = a[0];
    int r1 = r[0];
    bool no_solution = false;
    for (i = 1; i < n; ++i)
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
        x = (c / d * x % t + t) % t;
        r1 = m1 * x + r1;
        m1 = m1 * m2 / d;
    }
    if (no_solution) return -1;
    if (n == 1 && r1 == 0) return m1;
    return r1;
}

int m[9], a[9];
int main()
{
    int t, n, _;
    for (scanf("%d", &t), _ = 1; t--; ++_)
    {
        scanf("%d", &n);
        rep(i, n) scanf("%d", m + i);
        rep(i, n) scanf("%d", a + i);
        printf("Case %d: %d\n", _, chinese_remainder(n, m, a));
    }
    return 0;
}

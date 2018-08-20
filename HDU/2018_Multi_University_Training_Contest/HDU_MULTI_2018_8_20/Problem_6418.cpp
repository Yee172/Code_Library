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

int main()
{
    ll t, a, b, c, A, B, C, p, q, g;
    bool flag;
    for (scanf("%lld", &t); t--; )
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        scanf("%lld%lld%lld", &A, &B, &C);
        p = a * (B - C) + b * (C - A) + c * (A - B);
        q = a + b + c;
        flag = p < 0;
        if (p == 0) puts("0");
        else
        {
            p = abs(p);
            g = __gcd(p, q);
            p /= g;
            q /= g;
            if (q == 1)
            {
                if (flag) printf("-%lld\n", p);
                else printf("%lld\n", p);
            }
            else
            {
                if (flag) printf("-%lld/%lld\n", p, q);
                else printf("%lld/%lld\n", p, q);
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define square(x) ((x) * (x))

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

void extend_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b) {d = a; x = 1; y = 0;}
    else {extend_gcd(b, a % b, d, y, x); y -= x * (a / b);}
}

ll a, b, d, x, y;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~ scanf("%lld%lld", &a, &b))
    {
        d = 1;
        extend_gcd(a, b, d, x, y);
        if (d != 1) puts("sorry");
        else
        {
            while (x < 0) x += b, y -= a;
            printf("%lld %lld\n", x, y);
        }
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprllf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t, n, a, r;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        r = 1;
        rep(i, n) scanf("%lld", &a), r = r / __gcd(r, a) * a;
        printf("%lld\n", r);
    }
    return 0;
}

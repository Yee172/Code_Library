#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

#define MAXN 55
ll a[MAXN];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll n, x;
    scanf("%lld", &n);
    rep(i, n) scanf("%lld", a + i);
    printf("%lld\n", x = a[0] + a[1] - a[n - 1] >> 1);
    rep(i, n - 1) printf("%lld\n", a[i] - x);
    return 0;
}

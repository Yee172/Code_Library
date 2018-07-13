#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

ll dp[110];
ll fac[110];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    dp[1] = 0;
    dp[2] = 1;
    _rep(i, 100) dp[i + 2] = (i + 1) * (dp[i + 1] + dp[i]);
    fac[0] = 1;
    _rep(i, 100) fac[i] = i * fac[i - 1];
    ll t, n, m;
    scanf("%lld", &t);
    while (~ scanf("%lld%lld", &n, &m)) printf("%lld\n", dp[m] * (fac[n] / fac[m] / fac[n - m]));
    return 0;
}

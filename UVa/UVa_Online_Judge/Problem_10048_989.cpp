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

#define MAXN 105
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[MAXN][MAXN];
ll c, s, q;
ll u, v, w;
ll x, y;
ll t;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (scanf("%lld%lld%lld", &c, &s, &q) && (c || s || q))
    {
        if (t > 0) puts("");
        printf("Case #%lld\n", ++t);
        memset(dp, inf, sizeof dp);
        rep(i, s) scanf("%lld%lld%lld", &u, &v, &w), dp[u][v] = dp[v][u] = w;
        _rep(k, c) _rep(i, c) _rep(j, c) dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
        rep(i, q)
        {
            scanf("%lld%lld", &x, &y);
            if (dp[x][y] == inf) puts("no path");
            else printf("%lld\n", dp[x][y]);
        }
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

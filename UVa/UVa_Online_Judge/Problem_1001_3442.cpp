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

#define MAXN 115
const double eps = 1e-6;
struct ball
{
    ll x, y, z, r;
};
double cal(ball a, ball b)
{
    ll dis2 = square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z);
    double dis = sqrt(dis2) - a.r - b.r;
    if (fabs(dis) <= eps || dis < 0) return 0;
    return dis;
}
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll t;
double dp[MAXN][MAXN];
ll n;
ball balls[MAXN];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (scanf("%lld", &n) && n != -1)
    {
        printf("Cheese %lld: Travel time = ", ++t);
        _rep(i, n) scanf("%lld%lld%lld%lld", &balls[i].x, &balls[i].y, &balls[i].z, &balls[i].r);
        scanf("%lld%lld%lld", &balls[n + 1].x, &balls[n + 1].y, &balls[n + 1].z), balls[n + 1].r = 0;
        scanf("%lld%lld%lld", &balls[n + 2].x, &balls[n + 2].y, &balls[n + 2].z), balls[n + 2].r = 0;
        n += 2;
        _rep(i, n)
        {
            for (ll j = i; j <= n; j++)
                dp[i][j] = dp[j][i] = cal(balls[i], balls[j]);
        }
        _rep(k, n) _rep(i, n) _rep(j, n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        printf("%d sec\n", (int) round(dp[n - 1][n] * 10));
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

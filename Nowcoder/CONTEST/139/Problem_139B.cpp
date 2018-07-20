#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
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
 
ll n, m;
#define MOD m
#define MAXN 100050
ll a[MAXN];
inline void initialize(ll n)
{
    a[0] = 1, a[1] = 0;
    a[2] = a[3] = 1, a[4] = 6, a[5] = 22;
    for (ll i = 6; i <= n; i++)
    {
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]) % MOD - (i - 1) * (i - 2) / 2 * a[i - 3] % MOD;
        ((a[i] %= MOD) += MOD) %= MOD;
    }
}
 
signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~ scanf("%lld%lld", &n, &m))
    {
        initialize(n);
        printf("%lld\n", (a[n] % MOD + MOD) % MOD);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

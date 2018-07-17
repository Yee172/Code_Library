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

ll T;
#define MOD 0x3b9aca07
inline ll powmod(ll a,ll b)
{ ll r = 1; a %= MOD; for(; b; b >>= 1) {if (b & 1) r = r * a % MOD; a = a * a % MOD;} return r; }
inline ll inv(ll a) { return powmod(a, MOD - 2); }

#define MAXN 1000050
ll factorial[MAXN];
void init_factorial()
{
    factorial[0] = 1;
#ifdef MOD
    for (ll i = 1; i < MAXN; i++)
        factorial[i] = i * factorial[i - 1] % MOD;
#else
    for (ll i = 1; i < MAXN && i <= 20; i++)
        factorial[i] = i * factorial[i - 1];
    //MAXIMUM 20 for long long
#endif
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    init_factorial();
    scanf("%lld", &T);
    ll n, m, k;
    while (~ scanf("%lld%lld%lld", &n, &m, &k))
    {
        if (m == 1)
        {
            printf("%lld\n", n);
            continue;
        }
        if (n - k * m - m < 0)
        {
            puts("0");
            continue;
        }
        ll res = n;
        res *= factorial[n - k * m - 1];
        res %= MOD;
        res *= inv(factorial[n - k * m - m] * factorial[m - 1] % MOD * m);
        res %= MOD;
        printf("%lld\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

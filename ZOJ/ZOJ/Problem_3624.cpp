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

#define MOD 0x5f5e107
#define MAXN 200050


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


ll mod_inverse[MAXN];
ll factorial_inverse[MAXN];
void init_factorial_inverse()
{
    mod_inverse[0] = 0, factorial_inverse[0] = mod_inverse[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        mod_inverse[i] = (MOD - MOD / i) * mod_inverse[MOD % i] % MOD;
    for (ll i = 1; i < MAXN; i++)
        factorial_inverse[i] = factorial_inverse[i - 1] * mod_inverse[i] % MOD;
}


signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    init_factorial();
    init_factorial_inverse();
    ll m, n, p, q;
    while (~ scanf("%lld%lld%lld%lld", &m, &n, &p, &q))
    {
        ll res = factorial[m + n] * factorial[m - p + q] % MOD;
        res -= factorial[m + q] * factorial[m - p + n] % MOD;
        res %= MOD;
        res += MOD;
        res %= MOD;
        res *= factorial_inverse[m];
        res %= MOD;
        res *= factorial_inverse[n];
        res %= MOD;
        res *= factorial_inverse[m - p];
        res %= MOD;
        res *= factorial_inverse[q];
        res %= MOD;
        res += MOD;
        res %= MOD;
        printf("%lld\n", res);
    }
    return 0;
}

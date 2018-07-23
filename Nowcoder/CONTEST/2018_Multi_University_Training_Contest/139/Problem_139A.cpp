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
 
#define MOD 0x3b9aca07
#define MAXN 3050
 
ll factorial[MAXN];
ll mod_inverse[MAXN];
ll factorial_inverse[MAXN];
inline void init_factorial()
{
    factorial[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        factorial[i] = i * factorial[i - 1] % MOD;
    mod_inverse[0] = 0, factorial_inverse[0] = mod_inverse[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        mod_inverse[i] = (MOD - MOD / i) * mod_inverse[MOD % i] % MOD;
    for (ll i = 1; i < MAXN; i++)
        factorial_inverse[i] = factorial_inverse[i - 1] * mod_inverse[i] % MOD;
}
 
inline ll binomial(ll n, ll k)
{
    return factorial[n] * factorial_inverse[k] % MOD * factorial_inverse[n - k] % MOD;
}
 
signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    init_factorial();
    ll n, m;
    while (~ scanf("%lld%lld", &n, &m))
    {
        ll res = 0;
        res += binomial(m + n + 1, n) * binomial(m + n, n) % MOD * mod_inverse[n + 1] % MOD;
        printf("%lld\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

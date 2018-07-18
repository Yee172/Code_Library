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
#define MAXN 1000050
ll powmod(ll a,ll b)
{ ll r = 1; a %= MOD; for(; b; b >>= 1) {if (b & 1) r = r * a % MOD; a = a * a % MOD;} return r; }

ll mod_inverse[MAXN];
inline void init_factorial_inverse()
{
    mod_inverse[0] = 0, mod_inverse[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        mod_inverse[i] = (MOD - MOD / i) * mod_inverse[MOD % i] % MOD;
}

ll binomial_k[MAXN];
inline void initialize_binomial_k(ll k)
{
    binomial_k[0] = binomial_k[k] = 1;
    for (ll i = 1; i < k; i++)
        binomial_k[i] = binomial_k[i - 1] * (k - i + 1) % MOD * mod_inverse[i] % MOD;
}

ll sign[2] = {-1, 1};

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    init_factorial_inverse();
    int t, f;
    ll n, m, k, res;
    scanf("%d", &t);
    _rep(_, t)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        res = 0;
        f = 0;
        initialize_binomial_k(k);
        rep(i, k)
            res += sign[f = f ^ 1] * binomial_k[k - i] * (k - i) % MOD * powmod(k - i - 1, n - 1) % MOD;
        ((res %= MOD) += MOD) %= MOD;
        _rep(i, k)
            (res *= (m - i + 1) * mod_inverse[i] % MOD) %= MOD;
        printf("Case #%d: %lld\n", _, res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

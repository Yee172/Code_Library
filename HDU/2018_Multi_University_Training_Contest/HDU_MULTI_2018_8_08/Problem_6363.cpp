#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const ll MOD = 0x3b9aca07;
const ll MAXN = 1000050;
ll power2_fibonacci[MAXN];
ll factorial[MAXN * 2];
ll mod_inverse[MAXN];
ll factorial_inverse[MAXN];
inline void init()
{
    power2_fibonacci[0] = 1, power2_fibonacci[1] = 2;
    for (ll i = 2; i < MAXN; ++i)
        power2_fibonacci[i] = power2_fibonacci[i - 1] * power2_fibonacci[i - 2] % MOD;
    factorial[0] = 1;
    for (ll i = 1; i < MAXN * 2; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;
    mod_inverse[0] = 0, factorial_inverse[0] = mod_inverse[1] = 1;
    for (ll i = 2; i < MAXN; ++i)
        mod_inverse[i] = (MOD - MOD / i) * mod_inverse[MOD % i] % MOD;
    for (ll i = 1; i < MAXN; ++i)
        factorial_inverse[i] = factorial_inverse[i - 1] * mod_inverse[i] % MOD;
}

inline ll binomial(ll n, ll k) { return factorial[n] * factorial_inverse[n - k] % MOD * factorial_inverse[k] % MOD; }
ll powmod(ll a, ll b) { ll r = 1; a %= MOD; for(; b; b >>= 1) {if (b & 1) r = r * a % MOD; a = a * a % MOD;} return r; }

typedef int TYPE;
vector<TYPE> prime;
bool vis[MAXN];
int mu[MAXN];
inline void mobius_mu_sieve()
{
    mu[0] = 0, mu[1] = 1;
    for (TYPE i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i), mu[i] = -1;
        for (TYPE j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j]) mu[i * prime[j]] = -mu[i];
            else
            {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

void Main()
{
    init();
    mobius_mu_sieve();
    int t;
    ll n, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        ll tot = binomial(n + k - 1, n);
        ll x = tot;
        ll res = 0;
        for (int i = 3; i <= n; i++)
            if (n % i == 0)
            {
                ll cnt = 0;
                for (int j = i; j <= n; j += i) if (n % j == 0)
                        cnt += mu[j / i] * binomial(n / j + k - 1, k - 1);
                (res += (power2_fibonacci[i] - 1) * cnt % MOD) %= MOD;
                (((x -= cnt) %= MOD) += MOD) %= MOD;
            }
        printf("%lld\n", (res + x) % MOD * powmod(tot, MOD - 2) % MOD);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

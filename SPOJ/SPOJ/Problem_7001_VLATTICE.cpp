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

#define MAXN 1000050
vector<ll> prime;
bool vis[MAXN];
ll mu[MAXN];
void mobius_mu_sieve()
{
    mu[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i), mu[i] = -1;
        for (ll j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
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

int solve(ll n)
{
    ll res = 3; // 3 connected edge
    _rep(i, n) res += mu[i] * (n / i) * (n / i) * 3; // 3 connected surface
    _rep(i, n) res += mu[i] * (n / i) * (n / i) * (n / i); // the remain space
    printf("%lld\n", res);
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    mobius_mu_sieve();
    ll t, n;
    scanf("%lld", &t);
    while (~ scanf("%lld", &n)) solve(n);
    return 0;
}

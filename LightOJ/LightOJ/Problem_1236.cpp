#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000500
typedef long long ll;
ll t, _;
ll n;

vector<ll> prime;
bool vis[MAXN];
void euler_sieve()
{
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i);
        for (vector<ll>::iterator pr = prime.begin(); pr != prime.end(), i * *pr < MAXN; pr++)
        {
            vis[i * *pr] = 1;
            if (i % *pr == 0) break;
        }
    }
}

map<ll, ll> generate_factors(ll n)
{
    map<ll, ll> factors;
    ll k = 0;
    ll f = 2;
    while (f * f <= n)
    {
        while (n % f == 0)
        {
            factors[f]++;
            n /= f;
        }
        k++;
        f = prime[k];
    }
    if (n > 1) factors[n]++;
    return factors;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    euler_sieve();
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        scanf("%lld", &n);
        map<ll, ll> fac = generate_factors(n);
        ll res = 1;
        for (map<ll, ll>::iterator it = fac.begin(); it != fac.end(); it++) res *= 2 * it->second + 1;
        printf("Case %lld: %lld\n", _, res / 2 + 1);
    }
    return 0;
}

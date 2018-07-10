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
    ll i = 0;
    ll f = 2;
    while (f * f <= n)
    {
        while (n % f == 0)
        {
            factors[f]++;
            n /= f;
        }
        f = prime[i++];
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
        printf("Case %lld: ", _);
        scanf("%lld", &n);
        ll res = 1;
        map<ll, ll> a = generate_factors(n);
        for (map<ll, ll>::iterator it = a.begin(); it != a.end(); it++)
        {
            if (it->first == 2) continue;
            else res *= it->second + 1;
        }
        printf("%lld\n", res - 1);
    }
    return 0;
}

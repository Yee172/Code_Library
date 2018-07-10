#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000500
typedef long long ll;
ll power(ll a,ll b) {ll r = 1; for(; b; b >>= 1) {if (b & 1) r = r * a; a = a * a;} return r;}
ll t, _;
ll a, b, l;
ll i;

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
        scanf("%lld%lld%lld", &a, &b, &l);
        map<ll, ll> a_factors = generate_factors(a);
        map<ll, ll> b_factors = generate_factors(b);
        map<ll, ll> l_factors = generate_factors(l);
        ll c = 1;
        for (map<ll, ll>::iterator it = l_factors.begin(); it != l_factors.end(); it++)
        {
            if (max(a_factors[it->first], b_factors[it->first]) < it->second) c *= power(it->first, it->second);
        }
        ll ok = 1;
        for (map<ll, ll>::iterator it = a_factors.begin(); it != a_factors.end(); it++)
            if (it->second > l_factors[it->first])
            {
                ok = 0;
                break;
            }
        if (ok) for (map<ll, ll>::iterator it = b_factors.begin(); it != b_factors.end(); it++)
                if (it->second > l_factors[it->first])
                {
                    ok = 0;
                    break;
                }
        if (ok) printf("%lld\n", c);
        else puts("impossible");
    }
    return 0;
}

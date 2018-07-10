#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000050
typedef long long ll;
#define mod 1000003
ll powmod(ll a,ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}
ll inv(ll x) {return powmod(x, mod - 2);}
ll t;
ll n, k;
ll i;
ll fac[MAXN];

void gao()
{
    fac[0] = 1;
    for (i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * i % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    gao();
    scanf("%lld", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%lld%lld", &n, &k);
        printf("Case %lld: %lld\n", i, fac[n] * inv(fac[n - k]) % mod * inv(fac[k]) % mod);
    }
    return 0;
}

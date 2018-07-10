#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, _;
ll n, k, mod;
ll i;
ll powmod(ll a,ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        printf("Case %lld: ", _);
        scanf("%lld%lld%lld", &n, &k, &mod);
        ll res = 0;
        ll a;
        for (i = 0; i < n; i++) scanf("%lld", &a), res += a, res %= mod;
        res = res * k % mod * powmod(n, k - 1) % mod;
        printf("%lld\n", res);
    }
    return 0;
}

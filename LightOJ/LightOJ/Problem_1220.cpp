#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a,ll b) {ll r = 1; for(; b; b >>= 1) {if (b & 1) r = r * a; a = a * a;} return r;}
ll t, _;
ll n;
ll i;
int solve()
{
    scanf("%lld", &n);
    double a = log(abs(n));
    ll f = n > 0 ? 1 : -1;
    for (i = 32; i > 0; i--)
        if (power(f * round(exp(a / i)), i) == n) return printf("%lld\n", i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        printf("Case %lld: ", _);
        solve();
    }
    return 0;
}

#include<cstdio>
using namespace std;
typedef long long ll;
#define MAXN 10050
ll a[MAXN];
ll b[MAXN];


signed main(){
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll t;
    ll n;
    scanf("%lld", &t);
    for (ll cas = 1; cas <= t; cas++)
    {
        scanf("%lld", &n);
        ll ans = 0;
        for (ll i = 0; i < n; i++) scanf("%lld", a + i);
        for (ll i = 0; i < n; i++) scanf("%lld", b + i);
        for (ll i = 0; i < n; i++) ans += a[i] + b[i] > 10;
        printf("Case %lld: %lld\n", cas, ans);
    }
    return 0;
}
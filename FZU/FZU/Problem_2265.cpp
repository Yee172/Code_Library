#include<iostream>
#include<algorithm>
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
        sort(b, b + n);
        for (ll i = 0; i < n; i++) ans += lower_bound(b, b + n, a[i]) - b;
        printf("Case %lld: %.2f\n", cas, 1.0 * ans / n);
    }
    return 0;
}
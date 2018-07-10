#include<iostream>
using namespace std;
typedef long long ll;
#define MAXN 10050

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
        ll a;
        for (ll i = 0; i < n * 2; i++) scanf("%lld", &a);
        printf("Case %lld: %.2f\n", cas, 1.0 * n / 2);
    }
    return 0;
}
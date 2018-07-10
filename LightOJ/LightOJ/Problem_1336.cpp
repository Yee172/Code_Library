#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, _;
ll n;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        printf("Case %lld: ", _);
        scanf("%lld", &n);
        printf("%lld\n", n - (ll) sqrt(n) - (ll) sqrt(n / 2));
    }
    return 0;
}

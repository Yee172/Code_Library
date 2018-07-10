#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll a, b, c, d;
ll i;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        printf("Case %lld: %lld\n", i, __gcd(abs(a - c), abs(b - d)) + 1);
    }
    return 0;
}

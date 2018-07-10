#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000500
typedef long long ll;
ll t, _;
ll n, base;
ll i;
double digits[MAXN];

void gao()
{
    digits[0] = 0.0;
    for (i = 1; i < MAXN; i++)
        digits[i] = digits[i - 1] + log10(i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    gao();
    for (_ = 1; _ <= t; _++)
    {
        scanf("%lld%lld", &n, &base);
        ll res = ceil(digits[n] / log10(base));
        printf("Case %lld: %lld\n", _, max(1ll, res));
    }
    return 0;
}

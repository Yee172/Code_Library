#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000500
typedef long long ll;
ll t, _;
ll n;
ll i;
double j;
double a[MAXN];

void gao()
{
    a[0] = 0;
    j = 0;
    for (i = 1; i < MAXN * 100; i++)
    {
        j += 1.0 / i;
        if (i % 100 == 0) a[i / 100] = j;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    gao();
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        printf("Case %lld: ", _);
        scanf("%lld", &n);
        double res = a[n / 100];
        for (i = n / 100 * 100 + 1; i <= n; i++)
            res += 1.0 / i;
        printf("%.12f\n", res);
    }
    return 0;
}

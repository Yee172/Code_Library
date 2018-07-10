#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000500
typedef long long ll;
ll t;
ll n, r, p, q;
ll i, j;
ll n2[MAXN], n5[MAXN];

void gao()
{
    for (i = 2; i < MAXN; i++)
    {
        n2[i] = n2[i - 1];
        j = 2;
        while (i % j == 0) n2[i]++, j *= 2;
        n5[i] = n5[i - 1];
        j = 5;
        while (i % j == 0) n5[i]++, j *= 5;
    }
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
        scanf("%lld%lld%lld%lld", &n, &r, &p, &q);
        ll p2 = 0, p5 = 0;
        j = 2;
        while (p % j == 0) p2++, j *= 2;
        j = 5;
        while (p % j == 0) p5++, j *= 5;
        printf("Case %lld: %lld\n", i, min(n2[n] - n2[n - r] - n2[r] + p2 * q, n5[n] - n5[n - r] - n5[r] + p5 * q));
    }
    return 0;
}

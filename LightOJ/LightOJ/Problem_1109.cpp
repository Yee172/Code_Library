#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
typedef long long ll;
ll t;
ll n;
ll i, j;
pair<ll, ll> nd[MAXN];

bool cmp(pair<ll, ll> x, pair<ll, ll> y)
{
    return x.first < y.first || (x.first == y.first && x.second > y.second);
}

void gao()
{
    for (i = 1; i < MAXN; i++)
    {
        for (j = 1; j * j <= i; j++) if (i % j == 0)
        {
            nd[i].first++;
            if (j * j < i) nd[i].first++;
        }
        nd[i].second = i;
    }
    sort(nd + 1, nd + MAXN, cmp);
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
        scanf("%lld", &n);
        printf("Case %lld: %lld\n", i, nd[n].second);
    }
    return 0;
}

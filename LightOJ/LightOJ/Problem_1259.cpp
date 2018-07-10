#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000500
typedef long long ll;
ll t;
ll n;
ll i, j;
bool vis[MAXN];
vector<ll> prime;

void gao()
{
    for (i = 2; i < MAXN; i++) if (!vis[i])
        {
            prime.push_back(i);
            for (j = i * 2; j < MAXN; j+= i) vis[j] = 1;
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
        scanf("%lld", &n);
        ll res = 0;
        for (j = 0; prime[j] <= n / 2; j++) if (!vis[n - prime[j]]) res++;
        printf("Case %lld: %lld\n", i, res);
    }
    return 0;
}

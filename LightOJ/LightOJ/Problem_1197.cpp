#include <bits/stdc++.h>
using namespace std;
#define MAXN 100500
typedef long long ll;
#define square(x) ((x) * (x))
ll t, _;
ll a, b;
ll i, j;
bool v[MAXN];
vector<ll> prime;
bool vis[MAXN];


void gao()
{
    for (i = 2; i < MAXN; i++) if (!v[i])
        {
            prime.push_back(i);
            for (j = i * 2; j < MAXN; j += i) v[j] = 1;
        }
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
        scanf("%lld%lld", &a, &b);
        memset(vis, 0, sizeof(vis));
        for (i = 0; square(prime[i]) <= b; i++)
            for (j = ceil(a * 1.0 / prime[i]) * prime[i]; j <= b; j += prime[i])
                if (prime[i] != j)
                    vis[j - a] = 1;
        ll res = 0 - (a == 1);
        for (i = a; i <= b; i++)
            if (!vis[i - a])
                res++;
        printf("Case %lld: %lld\n", _, res);
    }
    return 0;
}

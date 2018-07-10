#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll const N = 250;
ll mp[N][N];

void floyd(ll n)
{
    for(ll k = 1; k <= n; k++)
        for(ll i = 1; i <= n; i++)
            for(ll j=1; j <= n; j++)
                mp[i][j] = mp[i][j] | mp[i][k] & mp[k][j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll n, m;
    ll u, v;
    ll cnt;
    ll res = 0;
    scanf("%lld%lld", &n, &m);
    for (ll i = 0; i < m; i++)
        scanf("%lld%lld", &u, &v), mp[u][v] = 1;
    floyd(n);
    for (ll i = 1; i <= n; i++)
    {
        cnt = 0;
        for (ll j = 1; j <= n; j++)
            cnt += mp[i][j] | mp[j][i];
        res += cnt == n - 1;
    }
    printf("%lld\n", res);
    return 0;
}

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
const ll N = 255;
#define square(x) ((x) * (x))
#define walk (3.0 / 500)
#define subway (3.0 / 2000)
double dp[N][N];
ll x[N];
ll y[N];
ll cnt;

inline double cal_distance(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt(square(x2 - x1) + square(y2 - y1));
}

void build(ll &x1, ll &y1, ll &x2, ll &y2)
{
    if (x1 == -1 && y1 == -1)
    {
        x1 = x[++cnt] = x2, y1 = y[cnt] = y2;
        return;
    }
    if (x2 == -1 && y2 == -1)
    {
        x1 = x2, y1 = y2;
        return;
    }
    dp[cnt + 1][cnt] = dp[cnt][cnt + 1] = cal_distance(x1, y1, x2, y2) * subway;
    x1 = x[++cnt] = x2, y1 = y[cnt] = y2;
}

ll vis[N];
double dis[N];
double dij(ll st, ll n, ll end)
{
    for (ll i = 1; i <= n; i++) dis[i] = 1e20, vis[i] = 0;
    priority_queue<pair<double, ll> > q;
    q.push(make_pair(dis[st] = 0, st));
    while (!q.empty())
    {
        ll u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (ll i = 1; i <= n; i++)
        {
            double w = dp[u][i];
            if (dis[i] > dis[u] + w)
            {
                dis[i] = dis[u] + w;
                q.push(make_pair(- dis[i], i));
            }
        }
    }
    return dis[end];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; j <= N; j++)
            dp[i][j] = 1e20;
    ll x1(-1), y1(-1), x2, y2;
    scanf("%lld%lld%lld%lld", x + 1, y + 1, x + 2, y + 2);
    cnt = 2;
    while (~ scanf("%lld%lld", &x2, &y2)) build(x1, y1, x2, y2);
    for (ll i = 1; i <= cnt; i++)
        for (ll j = 1; j < i; j++)
            dp[j][i] = dp[i][j] = min(dp[i][j], cal_distance(x[i], y[i], x[j], y[j]) * walk);
    printf("%ld\n", lround(dij(1, cnt, 2)));
    return 0;
}

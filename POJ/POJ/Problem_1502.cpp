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
ll const M = 1050;
ll const inf = 0x3f3f3f3f3f3f3f3f;

template <typename T> inline bool read(T &x)
{
    char c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar())
    {
        if (c == EOF) return false;
        if (c == '-') f = true;
        if (c == 'x') return x = -1, true;
    }
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    if (f) x = -x;
    return true;
}

struct edge
{
    ll u;
    ll v;
    ll w;
};
vector<edge> e[M];

inline void insert_edge(ll u, ll v, ll w)
{
    e[u].push_back(edge{u, v, w});
}

inline void insert_double_edge(ll u, ll v, ll w)
{
    insert_edge(u, v, w);
    insert_edge(v, u, w);
}

ll vis[N];
ll dis[N];

ll dij(ll st, ll n)
{
    for (ll i = 1; i <= n; i++) dis[i] = inf, vis[i] = 0;
    priority_queue<pair<ll, ll> > q;
    q.push(make_pair(dis[st] = 0, st));
    while (!q.empty())
    {
        ll u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (ll i = 0; i < e[u].size(); i++)
        {
            ll v = e[u][i].v;
            ll w = e[u][i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push(make_pair(- dis[v], v));
            }
        }
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++) res = max(res, dis[i]);
    return res;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll n;
    scanf("%lld", &n);
    ll w;
    for (ll i = 2; i <= n; i++)
        for (ll j = 1; j < i; j++)
        {
            read(w);
            if (w > 0) insert_double_edge(i, j, w);
        }
    printf("%lld\n", dij(1, n));
    return 0;
}

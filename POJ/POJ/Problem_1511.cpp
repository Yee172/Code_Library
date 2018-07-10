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
ll const N = 1000050;
ll const M = 2000050;
const static ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    ll y;
    ll w;
    edge * t;
}e[M];

ll top;

edge * li[N];

inline void ade(ll u, ll v, ll w)
{
    e[top].y = v;
    e[top].w = w;
    e[top].t = li[u];
    li[u] = &e[top++];
}

edge * lino[N];

inline void adeRev(ll u, ll v, ll w)
{
    e[top].y = v;
    e[top].w = w;
    e[top].t = lino[u];
    lino[u] = &e[top++];
}

inline void insert_double_edge(ll u, ll v, ll w)
{
    ade(u, v, w);
    adeRev(v, u, w);
}

ll vis[N];
ll dis[N];

ll dij(edge** li, ll st, ll n)
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
        for (edge * t = li[u]; t; t = t->t)
        {
            ll v = t->y;
            ll w = t->w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push(make_pair(- dis[v], v));
            }
        }
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++) res += dis[i];
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll t;
    ll n, m;
    ll u, v, w;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        for (ll i = 0; i < m; i++)
            scanf("%lld%lld%lld", &u, &v, &w), insert_double_edge(u, v, w);
        printf("%lld\n", dij(li, 1, n) + dij(lino, 1, n));
        memset(li, 0, sizeof li), memset(lino, 0, sizeof lino);
    }
    return 0;
}

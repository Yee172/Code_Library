#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const ll N = 100500;
const ll M = 100500;
const static ll inf = 0x3f3f3f3f3f3f3f3f;

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
    return dis[n];
}


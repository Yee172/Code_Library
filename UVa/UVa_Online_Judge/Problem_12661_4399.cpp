#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define square(x) ((x) * (x))

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

const ll M = 50005;
const ll N = 305;
const ll inf = 0x3f3f3f3f3f3f3f3f;

inline ll nearest(ll n, ll x)
{
    return (n - 1 + x) / x * x;
}

struct edge
{
    ll v;
    ll a;
    ll b;
    ll w;
    edge * next;
}e[M];

ll top;
edge * adjacency_list[N];

inline void insert_edge(ll u, ll v, ll a, ll b, ll w)
{
    e[top].v = v;
    e[top].a = a;
    e[top].b = b;
    e[top].w = w;
    e[top].next = adjacency_list[u];
    adjacency_list[u] = &e[top++];
}

ll dis[N];
ll vis[N];
ll dij(ll st, ll n, ll end)
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
        for (edge * t = adjacency_list[u]; t; t = t->next)
        {
            ll v = t->v;
            ll a = t->a;
            ll b = t->b;
            ll w = t->w;
            if (w > a) continue;
            ll near = nearest(dis[u], a + b);
            if (near - a - b <= dis[u] && dis[u] + w <= near - b) near = dis[u];
            if (dis[v] > near + w)
            {
                dis[v] = near + w;
                q.push(make_pair(- dis[v], v));
            }
        }
    }
    return dis[end];
}

ll T;
ll n, m, s, t;
ll u, v, a, b, w;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~scanf("%lld%lld%lld%lld", &n, &m, &s, &t))
    {
        top = 0;
        rep(i, N) adjacency_list[i] = NULL;
        rep(i, m) scanf("%lld%lld%lld%lld%lld", &u, &v, &a, &b, &w), insert_edge(u, v, a, b, w);
        printf("Case %lld: %lld\n", ++T, dij(s, n, t));
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

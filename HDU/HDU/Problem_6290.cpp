#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

const ll N = 100500;
const static ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    ll u;
    ll v;
    ll a;
    ll b;
};
vector<edge> e[N];

inline void insert_edge(ll u, ll v, ll a, ll b)
{
    e[u].push_back(edge{u, v, a, b});
}

ll vis[N];
ll level[N];
double dis[N];

double dij(ll st, ll n)
{
    for (ll i = 1; i <= n; i++) dis[i] = 1e20, vis[i] = 0, level[i] = 1;
    priority_queue<pair<double, ll> > q;
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
            ll a = e[u][i].a;
            ll b = e[u][i].b;
            double cost = log2(1.0 + 1.0 * a / level[u]);
            if (abs(cost - b) < 1e-10 || cost > b)
                if (dis[v] > dis[u] + cost)
                {
                    dis[v] = dis[u] + cost;
                    level[v] = level[u] + a;
                    q.push(make_pair(- dis[v], v));
                }
        }
    }
    return dis[n];
}

void solve(ll n, ll m)
{
    rep(i, n) e[i + 1].clear();
    ll u, v, a, b;
    rep(i, m) scanf("%lld%lld%lld%lld", &u, &v, &a, &b), insert_edge(u, v, a, b);
    double tmp = dij(1, n);
    tmp == 1e20 ? puts("-1") : printf("%lld\n", (ll) floor(tmp));
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t, n, m;
    scanf("%lld", &t);
    while (t--) scanf("%lld%lld", &n, &m), solve(n, m);
    return 0;
}

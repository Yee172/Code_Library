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
ll const N = 150;
ll const M = 1050;
const static ll inf = 0x3f3f3f3f3f3f3f3f;
map<string, ll> trans;

struct edge
{
    ll u;
    ll v;
    double w;
};
vector<edge> e[M];

inline void insert_edge(ll u, ll v, double w)
{
    e[u].push_back(edge{u, v, w});
}

inline void insert_double_edge(ll u, ll v, double w)
{
    insert_edge(u, v, w);
    insert_edge(v, u, w);
}

ll vis[N];
double dis[N];

bool spfa(ll st, ll n)
{
    queue<ll> q;
    for (ll i = 1; i <= n; ++i)
    {
        dis[i] = 0;
        vis[i] = 0;
    }
    q.push(st);
    dis[st] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = 0; i < e[u].size(); ++i)
        {
            ll v = e[u][i].v;
            double w = e[u][i].w;
            double tmp = dis[u] * w;
            if (dis[v] < tmp)
            {
                dis[v] = tmp;
                vis[v]++;
                if (vis[v] > n) return true;
                q.push(v);
            }
        }
    }
    if (dis[st] > 1) return true;
    return false;
}

void solve(ll n)
{
    string s, t;
    char a[N], b[N];
    ll m;
    double w;
    trans.clear();
    for (ll i = 0; i < M; i++) e[i].clear();
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);

    for (ll i = 1; i <= n; i++)
        scanf("%s", a), s = a, trans[s] = i;
    scanf("%lld", &m);
    for (ll i = 1; i <= m; i++)
        scanf("%s%lf%s", a, &w, b), s = a, t = b, insert_edge(trans[a], trans[b], w);
    printf(spfa(1, n) ? "Yes" : "No");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll n;
    ll t = 1;
    while (~ scanf("%lld", &n) && n) printf("Case %lld: ", t++), solve(n), puts("");
    return 0;
}

#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
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

const int N = 505;
const int INF = 0x3f3f3f3f;
int n, m;

struct edge
{
    int v;
    int w;
    unsigned long rev;
};
vector<edge> G[N];

inline void insert_edge(int u, int v, int w)
{
    G[u].push_back(edge{v, w, G[v].size()});
    G[v].push_back(edge{u, 0, G[u].size() - 1});
}

int level[N];
int iter[N];
inline void bfs(int s)
{
    memset(level, -1, sizeof level);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            edge &e = G[u][i];
            if (e.w > 0 && level[e.v] < 0)
            {
                level[e.v] = level[u] + 1;
                que.push(e.v);
            }
        }
    }
}

int dfs(int u, int t, int f)
{
    if (u == t) return f;
    for(int &i = iter[u]; i < G[u].size(); i++)
    {
        edge &e = G[u][i];
        if (level[u] < level[e.v] && e.w > 0)
        {
            int d = dfs(e.v, t, min(f, e.w));
            if (d > 0)
            {
                e.w -= d;
                G[e.v][e.rev].w += d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(int s, int t)
{
    int flow = 0;
    for (;;)
    {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    int S, D;
    int s = 0, t;
    int u, v, w;
    while (~scanf("%d%d", &n, &m))
    {
        t = 200 + n + 1;
        rep(i, N) G[i].clear();
        scanf("%d%d", &S, &D);
        insert_edge(s, S, INF);
        insert_edge(D + 200, t, INF);
        _rep(i, n)
        {
            scanf("%d", &w);
            insert_edge(i, i + 200, w);
            insert_edge(i + 200, i, w);
        }
        _rep(i, m)
        {
            scanf("%d%d", &u, &v);
            insert_edge(u + 200, v, INF);
            insert_edge(v + 200, u, INF);
        }
        n = t;
        printf("%d\n", dinic(0, n));
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

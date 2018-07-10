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

#define MAXE 10005
#define MAXN 105

struct edge
{
    ll u, v, w;
    bool operator<(const edge &b) const
    {
        return w < b.w;
    }
};

const ll inf = 0x3f3f3f3f3f3f3f3f;
edge wa[MAXE];
ll dsu[MAXN];
ll find(ll i)
{
    return dsu[i] == i ? i : (dsu[i] = find(dsu[i]));
}
ll x, y;
ll V, E;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~scanf("%lld%lld", &V, &E) && (V || E))
    {
        ll res = inf;
        rep(i, E) scanf("%lld%lld%lld", &wa[i].u, &wa[i].v, &wa[i].w);
        sort(wa, wa + E);
        rep(k, E)
        {
            ll tmp = 0;
            ll cnt = 0;
            rep(i, V + 1) dsu[i] = i;
            for (ll i = k; i < E; i++)
            {
                edge p = wa[i];
                x = find(p.u);
                y = find(p.v);
                if (x == y) continue;
                cnt++;
                dsu[y] = x;
                tmp = p.w;
                if (cnt >= V - 1) break;
            }
            if (cnt < V - 1) break;
            res = min(res, tmp - wa[k].w);
        }
        printf("%lld\n", res == inf ? -1 : res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

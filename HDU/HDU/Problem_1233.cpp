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
#define MAXN 200

struct edge
{
    ll u, v, w;
    bool operator<(const edge &b) const
    {
        return w < b.w;
    }
};

edge wa[MAXE];
ll dsu[MAXN];
ll find(ll i)
{
    return dsu[i] == i ? i : (dsu[i] = find(dsu[i]));
}
ll V, E;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (scanf("%lld", &V) && V)
    {
        E = V * (V - 1) / 2;
        for (ll i = 0; i < E; i++) scanf("%lld%lld%lld", &wa[i].u, &wa[i].v, &wa[i].w);
        for (ll i = 0; i <= V; i++) dsu[i] = i;
        sort(wa, wa + E);
        ll res = 0;
        for (ll i = 0; i < E; i++)
        {
            edge p = wa[i];
            ll x = find(p.v);
            ll y = find(p.u);
            if (x == y) continue;
            dsu[y] = x;
            res += p.w;
        }
        printf("%lld\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

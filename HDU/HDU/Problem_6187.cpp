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

#define MAXE 200005
#define MAXN 100005

struct edge
{
    ll u, v, w;
    bool operator<(const edge &b) const
    {
        return w > b.w;
    }
};

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
    while (~scanf("%lld%lld", &V, &E))
    {
        ll res = 0;
        rep(i, V) scanf("%lld%lld", &x, &y);
        rep(i, E) scanf("%lld%lld%lld", &wa[i].u, &wa[i].v, &wa[i].w), res += wa[i].w;
        sort(wa, wa + E);
        rep(i, V + 1) dsu[i] = i;
        ll cnt = 0;
        rep(i, E)
        {
            edge p = wa[i];
            x = find(p.u);
            y = find(p.v);
            if (x == y) continue;
            cnt++;
            res -= p.w;
            dsu[y] = x;
        }
        printf("%lld %lld\n", E - cnt, res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

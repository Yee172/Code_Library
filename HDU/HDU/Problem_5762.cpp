#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

const int MAXN = 100050;

int a[MAXN][2];
bool vis[MAXN << 1];
int t, n, m, d;

inline int __abs__(const int a) { return a < 0 ? -a : a; }

int solve()
{
    scanf("%d%d", &n, &m);
    memset(vis, false, sizeof(bool) * (m + 1 << 1));
    rep(i, n) scanf("%d%d", &a[i][0], &a[i][1]);
    rep(i, n) rep(j, i)
        {
            d = __abs__(a[i][0] - a[j][0]) + __abs__(a[i][1] - a[j][1]);
            if (vis[d]) return puts("YES");
            vis[d] = true;
        }
    return puts("NO");
}

int main()
{
    for (scanf("%d", &t); t--; ) { solve(); }
    return 0;
}

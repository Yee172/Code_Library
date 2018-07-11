#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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

#define MAXN 505
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
vector<pii> p;
int t, h, w, d, x, y;

bool cmp(pii b, pii c)
{
    return a[b.fi][b.se] > a[c.fi][c.se];
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    for (scanf("%d", &t); t; t--)
    {
        int cnt = 0;
        scanf("%d%d%d", &h, &w, &d);
        p.resize(h * w);
        rep(i, h) rep(j, w) scanf("%d", a[i] + j), p[cnt].fi = i, p[cnt++].se = j, vis[i][j] = 0;
        sort(p.begin(), p.end(), cmp);
        int res = 0;
        cnt = 0;
        for (auto it : p)
        {
            cnt++;
            x = it.fi;
            y = it.se;
            int m = a[x][y];
            if (vis[x][y]) continue;
            int tmp = 0;
            queue<pii> q;
            q.push(make_pair(x, y));
            while (!q.empty())
            {
                x = q.front().fi;
                y = q.front().se;
                q.pop();
                if (vis[x][y])
                {
                    if (vis[x][y] != cnt) tmp = -1;
                    continue;
                }
                if (a[x][y] == m && tmp >= 0) tmp++;
                if (m - a[x][y] < d)
                {
                    vis[x][y] = cnt;
                    if (x) q.push(make_pair(x - 1, y));
                    if (x < h - 1) q.push(make_pair(x + 1, y));
                    if (y) q.push(make_pair(x, y - 1));
                    if (y < w - 1) q.push(make_pair(x, y + 1));
                }
            }
            if (tmp >= 0) res += tmp;
        }
        printf("%d\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

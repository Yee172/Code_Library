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

int mov[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};
char a[5], b[5];
int st[2], ed[2];
bool vis[9][9];

inline void get(const char * s, int * a)
{
    a[0] = s[0] - 'a' + 1, a[1] = s[1] - '0';
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~ scanf("%s%s", a, b))
    {
        int r = 0;
        get(a, st), get(b, ed);
        memset(vis, 0, sizeof vis);
        queue<pair<pair<int, int>, int> > q;
        q.push(mp(mp(st[0], st[1]), 0));
        while (!q.empty())
        {
            int x = q.front().fi.fi;
            int y = q.front().fi.se;
            int t = q.front().se;
            q.pop();
            if (x == ed[0] && y == ed[1])
            {
                r = t;
                break;
            }
            if (vis[x][y]) continue;
            vis[x][y] = true;
            rep(i, 8)
            {
                int dx = mov[i][0];
                int dy = mov[i][1];
                if (0 < x + dx && x + dx < 9 && 0 < y + dy && y + dy < 9)
                    q.push(mp(mp(x + dx, y + dy), t + 1));
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n", a, b, r);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

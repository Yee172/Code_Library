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

#define MAXN 3050
pair<pii, int> point[MAXN];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    time_t __START__ = clock();
#endif
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        n *= 3;
        _rep(i, n) scanf("%d%d", &point[i].fi.fi, &point[i].fi.se), point[i].se = i;
        sort(point + 1, point + n + 1);
        _rep(i, n) printf("%d%c", point[i].se, i % 3 ? ' ' : '\n');
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

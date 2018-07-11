#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int i = 1; (i) <= (n); (i)++)
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

#define MAXN 100050

int t;
int n, q;
int x, y, z;
int a[MAXN << 2], timee[MAXN << 2];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    scanf("%d", &t);
    _rep(_, t)
    {
        scanf("%d%d", &n, &q);
        int bit = 1;
        while (bit <= n) bit <<= 1;
        _rep(i, bit + n) a[i] = 1, timee[i] = 0;
        _rep(i, q)
        {
            scanf("%d%d%d", &x, &y, &z);
            for (int l = bit + x - 1, r = bit + y + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
            {
                if (~ l & 1) a[l ^ 1] = z, timee[l ^ 1] = i;
                if (r & 1) a[r ^ 1] = z, timee[r ^ 1] = i;
            }
        }
        _rep(i, bit - 1)
        {
            if (timee[i] > timee[i << 1])
                a[i << 1] = a[i], timee[i << 1] = timee[i];
            if (timee[i] > timee[i << 1 | 1])
                a[i << 1 | 1] = a[i], timee[i << 1 | 1] = timee[i];
        }
        int res = 0;
        _rep(i, n) res += a[i + bit];
        printf("Case %d: The total value of the hook is %d.\n", _, res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

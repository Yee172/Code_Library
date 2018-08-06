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

#define MAXN 100050
pair<int, int> a[MAXN];
char s[MAXN];
inline int sign(int n) { return n < 0 ? -1 : n > 0; }

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    time_t __START__ = clock();
#endif
    int t, n, len, res, right_bracket, left_bracket;
    scanf("%d", &t);
    while (t--)
    {
        res = 0;
        scanf("%d", &n);
        rep(i, n)
        {
            scanf("%s", s);
            len = static_cast<int>(strlen(s));
            right_bracket = left_bracket = 0;
            rep(j, len)
            {
                if (s[j] == ')')
                {
                    if (left_bracket) res += 2, left_bracket--;
                    else right_bracket++;
                }
                else left_bracket++;
            }
            a[i].fi = right_bracket;
            a[i].se = -left_bracket;
        }
        sort(a, a + n, [&](const pair<int, int> &a, const pair<int, int> &b)
        { int da = min(a.fi, -b.se), db = min(b.fi, -a.se); return da == db ? a.fi < b.fi : da < db; });
        left_bracket = 0;
        rep(i, n)
        {
            if (a[i].fi < left_bracket) res += 2 * a[i].fi, left_bracket -= a[i].se + a[i].fi;
            else res += 2 * left_bracket, left_bracket = -a[i].se;
        }
        printf("%d\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

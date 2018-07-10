#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t, n, m;
    scanf("%lld", &t);
    rep(_, t)
    {
        printf("Problem %lld:\n", _ + 1001);
        scanf("%lld%lld", &n, &m);
        ll x = -1;
        ll a;
        rep(i, n)
        {
            scanf("%lld", &a);
            if (x == -1) x = a;
            x = min(x, a);
        }
        x == -1 ? puts("Shortest judge solution: N/A bytes.") : printf("Shortest judge solution: %lld bytes.\n", x);
        x = -1;
        rep(i, m)
        {
            scanf("%lld", &a);
            if (x == -1) x = a;
            x = min(x, a);
        }
        x == -1 ? puts("Shortest team solution: N/A bytes.") : printf("Shortest team solution: %lld bytes.\n", x);
    }
    return 0;
}

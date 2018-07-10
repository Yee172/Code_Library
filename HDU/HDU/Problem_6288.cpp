#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
ll power(ll a,ll b) {ll r = 1; for(; b; b >>= 1) {if (b & 1) r = r * a; a = a * a;} return r;}

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
    ll t;
    ll a, b, k;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &a, &b, &k);
        ll l = 0;
        ll r = (ll) 1e17;
        while (l < r)
        {
            ll n = l + ((r - l + 1) >> 1);
            ll logn = (ll) ceil(log2(n));
            double tmp = a * log2(n) + b * log2(logn);
            if (tmp > 60) r = n - 1;
            else
            {
                ll ttmp = power(n, a) * power(logn, b);
                if (ttmp > k) r = n - 1;
                else l = n;
            }
        }
        printf("%lld\n", l);
    }
    return 0;
}

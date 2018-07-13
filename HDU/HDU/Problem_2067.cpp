#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

#define MAXN 40
ll catalan[MAXN];
#ifdef mod
ll modinv[MAXN];
#endif
void init_catalan()
{
    catalan[1] = 1;
#ifdef mod
    modinv[0] = 0, modinv[1] = 1;
    for (ll i = 2; i < MAXN; i++) modinv[i] = (mod - mod / i) * modinv[mod % i] % mod;
    for (ll i = 2; i < MAXN; i++) catalan[i] = catalan[i - 1] * (4 * i - 2) % mod * modinv[i + 1] % mod;
#else
    for (ll i = 2; i < MAXN, i <= 33; i++) catalan[i] = catalan[i - 1] * (4 * i - 2) / (i + 1); // MAXIMUM 35
    if (MAXN > 34) catalan[34] = 812944042149730764;
    if (MAXN > 35) catalan[35] = 3116285494907301262;
#endif
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    init_catalan();
    ll t = 1, n;
    while (~ scanf("%lld", &n) && n >= 0) printf("%lld %lld %lld\n", t++, n, catalan[n] * 2);
    return 0;
}

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

#define MAXN 50
ll derangement[MAXN];
void init_derangement()
{
    derangement[1] = 0, derangement[2] = 1;
#ifdef mod
    for (ll i = 3; i < MAXN; i++)
        derangement[i] = (i - 1) * ((derangement[i - 1] + derangement[i - 2]) % mod) % mod;
#else
    for (ll i = 3; i < MAXN, i <= 20; i++)
        derangement[i] = (i - 1) * (derangement[i - 1] + derangement[i - 2]);
    //MAXIMUM 20
#endif
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    init_derangement();
    ll n;
    while (~ scanf("%lld", &n)) printf("%lld\n", derangement[n]);
    return 0;
}

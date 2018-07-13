#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

#define TYPE ll
#define MAXN 2005
#define mod 1000


TYPE bell[MAXN];
TYPE temp[MAXN];
void init_bell()
{
    bell[0] = bell[1] = temp[0] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        temp[i - 1] = bell[i - 1];
        for (ll j = i - 2; j >= 0; j--)
            temp[j] = (temp[j] + temp[j + 1]) % mod;
        bell[i] = temp[0];
    }
}


signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    init_bell();
    ll n, x;
    scanf("%lld", &n);
    while (n--) scanf("%lld", &x), printf("%lld\n", bell[x]);
    return 0;
}

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

#define MAXN 2000000000

vector<ll> a;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    a.push_back(0);
    a.push_back(1);
    a.push_back(3);
    for (ll i = 3, k = 0; k <= MAXN;i++)
    {
        k = *(a.end() - 1) + (lower_bound(a.begin(), a.end(), i) - a.begin());
        a.push_back(k);
    }
    ll n;
    while (~ scanf("%lld", &n) && n) printf("%ld\n", lower_bound(a.begin(), a.end(), n) - a.begin());
    return 0;
}

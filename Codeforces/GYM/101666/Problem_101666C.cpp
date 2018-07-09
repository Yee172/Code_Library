#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
vector<ll> tmp;
unordered_set<ll> ans;

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

signed main() {
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll n, a;
    scanf("%lld", &n);
    rep(k, n)
    {
        scanf("%lld", &a);
        for (ll i = 0; i < tmp.size(); i++) tmp[i] = __gcd(tmp[i], a);
        tmp.push_back(a);
        tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
        for (auto p: tmp) ans.insert(p);
    }
    printf("%lu\n", ans.size());
    return 0;
}

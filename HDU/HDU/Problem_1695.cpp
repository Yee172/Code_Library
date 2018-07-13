#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

#define MAXN 1000050
vector<ll> prime;
ll mo[MAXN];
bool vis[MAXN];
void Mobius()
{
    mo[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i), mo[i] = -1;
        for (ll j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
        {
            if (i * prime[j] >= MAXN) break;
            vis[i * prime[j]] = true;
            if (i % prime[j]) mo[i * prime[j]] = -mo[i];
            else
            {
                mo[i * prime[j]] = 0;
                break;
            }
        }
    }
}

int solve(ll _)
{
    ll a, b, c, d, k;
    ll r1 = 0, r2 = 0;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
    printf("Case %lld: ", _);
    if (k == 0) return puts("0");
    b /= k, d /= k;
    _rep(i, min(b, d)) r1 += mo[i] * (b / i) * (d / i);
    _rep(i, min(b, d)) r2 += mo[i] * (min(b, d) / i) * (min(b, d) / i);
    printf("%lld\n", r1 - r2 / 2);
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    Mobius();
    ll t;
    scanf("%lld", &t);
    _rep(_, t) solve(_);
    return 0;
}

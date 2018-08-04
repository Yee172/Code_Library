#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

template <typename T>
inline T square(const T x) { return x * x; }
inline int sign(const int x) { return x < 0 ? -1 : x > 0; }
const double eps = 1e-8;
inline int sign(const double x) { return x < -eps ? -1 : x > eps; }

#define MAXN 1000001
const ll MOD = 0x3b800001;
ll mod_inverse[MAXN];

void Main()
{
    mod_inverse[0] = 0, mod_inverse[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        mod_inverse[i] = (MOD - MOD / i) * mod_inverse[MOD % i] % MOD;
    int t;
    ll n, m;
    scanf("%d", &t);
    _rep(_, t)
    {
        scanf("%lld%lld", &n, &m);
        ll res = 0;
        ll tmp = m % MOD;
        for (ll i = 0; i < n && i < m; i++)
        {
            (res += tmp) %= MOD;
            (tmp *= mod_inverse[i + 1] * ((n - 1 - i) % MOD) % MOD * ((m - 1 - i) % MOD) % MOD) %= MOD;
        }
        printf("Case #%d: %lld\n", _, res);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

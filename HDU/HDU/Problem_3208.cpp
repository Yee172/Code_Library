#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.h"
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

vector<ll> a;

inline ll pow(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            if (a > ((1e18 + 1e5) / res)) return -1;
            res *= a;
        }
        if (b > 1 && a > (1ll << 31)) return -1;
        a *= a;
    }
    return res;
}

ll get_num(ll n, ll k)
{
    ll res = static_cast<ll>(pow(n, 1. / k));
    for (ll i = pow(res + 1, k); i <= n && i != -1; res++, i = pow(res + 1, k));
    for (ll i = pow(res, k); i > n || i == -1; res--, i = pow(res, k));
    return res;
}

ll get_power_sum(ll n)
{
    ll res = 0;
    a.resize(2);
    a[0] = 0;
    a[1] = n - 1;
    for (ll i = 2; i < 61; i++)
    {
        ll tmp = get_num(n, i) - 1;
        if (tmp == 0) break;
        a.push_back(tmp);
    }
    for (ll i = static_cast<ll>(a.size() - 1); i > 0; i--)
    {
        res += i * a[i];
        for (ll j = 1; j < i; j++)
            if (i % j == 0)
                a[j] -= a[i];
    }
    return res;
}

void Main()
{
    ll a, b;
    while (~ scanf("%lld%lld", &a, &b) && (a || b))
    {
        printf("%lld\n", get_power_sum(b) - get_power_sum(a - 1));
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

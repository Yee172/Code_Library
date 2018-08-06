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

vector<ll> a;

ll pow(ll a, ll b)
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

inline ll get_num(ll n, ll k)
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
    for (ll i = static_cast<ll>(a.size() - 1); i > 1; i--)
    {
        res += a[i];
        for (ll j = 2; j < i; j++)
            if (i % j == 0)
                a[j] -= a[i];
    }
    return res;
}

void Main()
{
    ll n;
    while (~ scanf("%lld", &n)) printf("%lld\n", get_power_sum(n) + 1);
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

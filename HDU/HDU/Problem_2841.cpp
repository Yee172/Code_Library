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

#define MAXN 100050
vector<ll> prime;
bool vis[MAXN];
ll mu[MAXN];
void mobius_mu_sieve()
{
    mu[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i), mu[i] = -1;
        for (ll j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j]) mu[i * prime[j]] = -mu[i];
            else
            {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

void Main()
{
    mobius_mu_sieve();
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        ll res = 0;
        if (n > m) n ^= m, m ^= n, n ^= m;
        _rep(i, n) res += mu[i] * (n / i) * (m / i);
        printf("%lld\n", res);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

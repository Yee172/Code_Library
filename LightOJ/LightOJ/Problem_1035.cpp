#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define square(x) ((x) * (x))

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

#define MAXN 105
vector<ll> prime;
bool vis[MAXN];
void euler_sieve()
{
    vis[0] = vis[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i);
        for (ll j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll factors[105];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    euler_sieve();
    ll t, n;
    scanf("%lld", &t);
    _rep(_, t)
    {
        ll cnt = 0;
        scanf("%lld", &n);
        printf("Case %lld: %lld =", _, n);
        memset(factors, 0, sizeof factors);
        for (ll i = 2; i <= n; i++)
        {
            ll j = i;
            for (ll k = 0; k < prime.size(); k++)
            {
                ll p = prime[k];
                if (p * p > j) break;
                while (j % p == 0)
                {
                    factors[p]++;
                    j /= p;
                }
            }
            if (j > 1) factors[j]++;
        }
        _rep(i, n) if (factors[i])
            {
                if (cnt) putchar(' '), putchar('*');
                cnt++;
                printf(" %lld (%lld)", i, factors[i]);
            }
        puts("");
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

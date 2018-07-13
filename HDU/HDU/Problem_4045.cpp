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

#define mod 0x3b9aca07
#define TYPE ll
#define MAXN 2005
#define MAXNN 1005

vector<TYPE> binomial[MAXN];
void init_binomial()
{
    for (ll i = 0; i < MAXN; i++)
        binomial[i] = vector<TYPE>((unsigned) i + 1, 1);
    for (ll i = 1; i < MAXN; i++)
    {
        for (ll j = 1; j < i; j++)
        {
#ifdef mod
            binomial[i][j] = (binomial[i - 1][j] + binomial[i - 1][j - 1]) % mod;
#else
            binomial[i][j] = binomial[i - 1][j] + binomial[i - 1][j - 1];
#endif
        }
    }
}


vector<TYPE> stirling_second[MAXNN];
void init_stirling_second()
{
    for (ll i = 0; i < MAXNN; i++)
        stirling_second[i] = vector<TYPE>((unsigned) i + 1, 0);
    for (ll i = 1; i < MAXNN; i++)
    {
        for (ll j = 1; j < i; j++)
        {
#ifdef mod
            stirling_second[i][j] = (j * stirling_second[i - 1][j] % mod + stirling_second[i - 1][j - 1]) % mod;
#else
            stirling_second[i][j] = j * stirling_second[i - 1][j] + stirling_second[i - 1][j - 1];
#endif
        }
        stirling_second[i][i] = (TYPE) 1;
    }
}


signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    init_binomial();
    init_stirling_second();
    ll n, r, k, m;
    while (~scanf("%lld%lld%lld%lld", &n, &r, &k, &m))
    {
        ll p = n - k * (r - 1) - 1;
        if (p < 0) puts("0");
        else
        {
            ll res = 0;
            for (ll i = 1; i <= min(m, r); i++)
                res = (res + stirling_second[r][i]) % mod;
            res *= binomial[r + p][r];
            printf("%lld\n", res % mod);
        }
    }
    return 0;
}

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

#define MAXN 2050
#define TYPE ll
#define mod 0x3b9aca07

vector<TYPE> stirling_first[MAXN];
void init_stirling_first()
{
    for (ll i = 0; i < MAXN; i++)
        stirling_first[i] = vector<TYPE>((unsigned) i + 1, 0);
    for (ll i = 1; i < MAXN; i++)
    {
        for (ll j = 1; j < i; j++)
#ifdef mod
            stirling_first[i][j] = ((i - 1) * stirling_first[i - 1][j] % mod + stirling_first[i - 1][j - 1]) % mod;
#else
            stirling_first[i][j] = (i - 1) * stirling_first[i - 1][j] + stirling_first[i - 1][j - 1];
#endif
        stirling_first[i][i] = (TYPE) 1;
    }
}

vector<TYPE> binomial[MAXN];
void init_binomial()
{
    for (ll i = 0; i < MAXN; i++)
        binomial[i] = vector<TYPE>((unsigned) i + 1, 1);
    for (ll i = 1; i < MAXN; i++)
    {
        for (ll j = 1; j < i; j++)
#ifdef mod
            binomial[i][j] = (binomial[i - 1][j] + binomial[i - 1][j - 1]) % mod;
#else
            binomial[i][j] = binomial[i - 1][j] + binomial[i - 1][j - 1];
#endif
    }
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    init_stirling_first();
    init_binomial();
    ll t, n, f, b;
    for (scanf("%lld", &t); t--;)
    {
        scanf("%lld%lld%lld", &n, &f, &b);
        if (f + b - 2 >= n) puts("0");
        else printf("%lld\n", binomial[f + b - 2][f - 1] * stirling_first[n - 1][f + b - 2] % mod);
    }
    return 0;
}

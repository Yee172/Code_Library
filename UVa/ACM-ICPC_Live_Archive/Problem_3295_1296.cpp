#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
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

#define MAXN 1050

inline ll binomial(ll n, ll k)
{
    if (k > n) return 0;
    ll res = 1;
    rep(i, k) res *= n - i, res /= i + 1;
    return res;
}

ll dp[MAXN][MAXN];
ll diagonal_num[MAXN][MAXN];

inline void initialize()
{
    _rep(i, 1000)
        _rep(j, 1000)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (__gcd(i, j) - 1);
    _rep(i, 1000)
        _rep(j, 1000)
            diagonal_num[i][j] = diagonal_num[i - 1][j] + diagonal_num[i][j - 1] - diagonal_num[i - 1][j - 1] + dp[i][j];
}

int case_num;
signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    initialize();
    ll m, n, res;
    while (~ scanf("%lld%lld", &m, &n) && (m || n))
    {
        res = binomial((n + 1) * (m + 1), 3) - (n + 1) * binomial(m + 1, 3) - (m + 1) * binomial(n + 1, 3) - 2 * diagonal_num[m][n];
        printf("Case %d: %lld\n", ++case_num, res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

#include <bits/stdc++.h>
#pragma optimize("Ofast")

using namespace std;

void __LOCAL_TEST__()
{
    static int __INDEX__ = 0;
    static time_t __START__;
    static time_t __TEMP__;
    static time_t __END__;
    if (__INDEX__)
    {
        __END__ = clock();
        fprintf(stderr,
                "┏TIME CONSUMED BY STAGE %d: %.12f ms\n"
                "┗TOTAL TIME UNTIL STAGE %d: %.12f ms\n",
                __INDEX__,
                (__END__ - __TEMP__) / (double)CLOCKS_PER_SEC * 1000,
                __INDEX__,
                (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
        __TEMP__ = __END__;
        __INDEX__++;
    }
    else
    {
        freopen("../in.txt", "r", stdin);
        freopen("../out.txt", "w", stdout);
        __START__ = __TEMP__ = clock();
        __INDEX__++;
    }
}

#ifdef Yee_172
#define _______ __LOCAL_TEST__();
#else
#define _______ ;
#endif

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
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
#define square(x) ((x) * (x))
inline int sign(const int x) { return x < 0 ? -1 : x > 0; }

signed main()
{
    _______
    int n, num = 0;
    ll res = 0;
    scanf("%d", &n);
    vector<int> prime;
    vector<bool> vis(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime.push_back(i), res += n / i * (num++);
        for (ll j = 0; j < prime.size(), i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%lld\n", res * 2);
    _______
    return 0;
}

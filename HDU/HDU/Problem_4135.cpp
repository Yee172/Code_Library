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
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

int n, cnt;
int factor[60];

namespace euler_sieve
{
    typedef int TYPE;
    const TYPE MAXN = 1000050;
    TYPE prime[MAXN];
    int cnt = 0;
    bool vis[MAXN];
    void euler_sieve()
    {
        vis[0] = vis[1] = true;
        for (TYPE i = 2; i < MAXN; i++)
        {
            if (!vis[i]) prime[cnt++] = i;
            for (TYPE j = 0; j < cnt, i * prime[j] < MAXN; j++)
            {
                vis[i * prime[j]] = true;
                if (i % prime[j] == 0) break;
            }
        }
    }
}
using euler_sieve::prime;

inline void initialize()
{
    cnt = 0;
    for (int i = 0; i < euler_sieve::cnt && prime[i] * prime[i] <= n; ++i)
    {
        if (n % prime[i] == 0)
        {
            factor[cnt++] = prime[i];
            while (n % prime[i] == 0) n /= prime[i];
        }
    }
    if (n > 1) factor[cnt++] = n;
}

inline ll cal(const ll x)
{
    ll mul, num, res = 0;
    for (int s = (1 << cnt) - 1; s > 0; --s)
    {
        mul = 1;
        num = 0;
        for (int i = 0; i < cnt; ++i) if ((1 << i) & s) mul *= factor[i], ++num;
        res += (num & 1 ? 1 : -1) * (x / mul);
    }
    return x - res;
}

int main()
{
    int t, cas;
    ll a, b;
    euler_sieve::euler_sieve();
    for (cas = 1, scanf("%d", &t); t--; ++cas)
    {
        scanf("%lld%lld%d", &a, &b, &n);
        initialize();
        _debug(vector<int>(factor, factor + 10))
        printf("Case #%d: %lld\n", cas, cal(b) - cal(a - 1));
    }
    return 0;
}

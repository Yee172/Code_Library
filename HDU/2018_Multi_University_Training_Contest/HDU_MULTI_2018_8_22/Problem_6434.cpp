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

const int MAXN = 20000050;
namespace euler_function_sieve
{
    typedef long long TYPE;
    vector<TYPE> prime;
    bool vis[MAXN];
    TYPE phi[MAXN];
    void euler_function_sieve()
    {
        phi[0] = 0, phi[1] = 1;
        for (TYPE i = 2; i < MAXN; i++)
        {
            if (!vis[i]) prime.push_back(i), phi[i] = i - 1;
            for (TYPE j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
            {
                vis[i * prime[j]] = true;
                if (i % prime[j] == 0)
                {
                    phi[i * prime[j]] = phi[i] * prime[j];
                    break;
                }
                else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
        rep(i, MAXN) if(i & 1) phi[i] >>= 1;
    }
}
using euler_function_sieve::phi;

ll res[MAXN];

int main()
{
    euler_function_sieve::euler_function_sieve();
    for (int i = 2; i < MAXN; ++i) res[i] = res[i - 1] + phi[i];
    int t, n;
    for (scanf("%d", &t); t--; ) scanf("%d", &n), printf("%lld\n", res[n]);
    return 0;
}

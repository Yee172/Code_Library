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

typedef int TYPE;
const TYPE MAXN = 1000005;
vector<TYPE> prime;
bool vis[MAXN];
int mu[MAXN];
TYPE phi[MAXN];
TYPE inv[MAXN];
int t, m, n, p;

inline int __add__(int a, const int b) { a += b; return a < p ? a : a - p; }
inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + p : a; }
inline int __mul__(ll a, const int b) { a *= b; return (int) (a < p ? a : a - a / p * p); }
inline int __mod__(const ll a, const int b) { return (int) (a < b ? a : a - a / b * b); }
inline int __mod__(const int a) { return a < p ? (a < 0 ? a + p : a) : a - a / p * p; }

void Main()
{
    mu[0] = 0, mu[1] = 1;
    phi[0] = 0, phi[1] = 1;
    for (TYPE i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i), mu[i] = -1, phi[i] = i - 1;
        for (TYPE j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j])
            {
                mu[i * prime[j]] = -mu[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
            else
            {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
    inv[0] = 0, inv[1] = 1;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d%d", &m, &n, &p);
        if (n > m) n ^= m, m ^= n, n ^= m;
        for (int i = 2; i <= m; ++i) inv[i] = __mul__(p - p / i, inv[__mod__(p, i)]);
        int res = 0;
        _rep(i, n)
        {
            int _n = n / i;
            int _m = m / i;
            int cnt = 0;
            _rep(j, _n) cnt = __mod__(__add__(cnt, mu[j] * __mul__(__mod__((_n / j)), __mod__((_m / j)))));
            res = __add__(res, __mul__(__mul__(cnt, i), inv[phi[i]]));
        }
        printf("%d\n", res);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

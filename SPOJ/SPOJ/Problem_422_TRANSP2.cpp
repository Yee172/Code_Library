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

const int MOD = 1000003;
const int MAXN = 1000050;
int power_2[MAXN];
int mod_inverse[MAXN];
int prime[MAXN / 10];
int cnt;
int phi[MAXN];
bool vis[MAXN];

inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
inline int __add__(int a, const int b) { a += b; return a < MOD ? a : a - MOD; }

int main()
{
    power_2[0] = mod_inverse[1] = phi[1] = 1;
    for (int i = 1; i < MAXN; ++i) power_2[i] = __mul__(power_2[i - 1], 2);
    for (int i = 2; i < MAXN; ++i) mod_inverse[i] = __mul__(MOD - MOD / i, mod_inverse[MOD - MOD / i * i]);
    for (int i = 2; i < MAXN; ++i)
    {
        if (!vis[i]) prime[cnt++] = i, phi[i] = i - 1;
        for (int j = 0; j < cnt, i * prime[j] < MAXN; j++)
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
    int t, a, b, s, g, res;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &a, &b);
        if (!(a || b))
        {
            puts("0");
            continue;
        }
        s = a + b;
        g = __gcd(a, s);
        s /= g;
        res = 0;
        for (int i = 1; i * i <= s; ++i)
            if (s % i == 0)
            {
                if (i * i == s) res = __add__(res, __mul__(power_2[i * g], phi[i]));
                else res = __add__(res, __add__(__mul__(power_2[i * g], phi[s / i]), __mul__(power_2[s / i * g], phi[i])));
            }
        res = __mul__(res, mod_inverse[s]);
        s *= g;
        res = __sub__(power_2[s], res);
        printf("%d\n", res);
    }
    return 0;
}

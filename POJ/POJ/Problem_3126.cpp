#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
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

#define MAXN 10005
vector<ll> prime;
bool not_prime[MAXN];
void euler_sieve()
{
    not_prime[0] = not_prime[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (!not_prime[i]) prime.push_back(i);
        for (ll j = 0; j < prime.size(), i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll a, b;
ll t;

bool vis[MAXN];
ll gao[200000], gaogao[200000];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    euler_sieve();
    rep(i, 1000) not_prime[i] = 1;
    scanf("%lld", &t);
    bool wa;
    ll head, tail, next;
    while (t--)
    {
        scanf("%lld%lld", &a, &b);
        wa = false;
        head = 0;
        tail = 0;
        gao[0] = a;
        gaogao[0] = 0;
        memset(vis, 0, sizeof vis);
        while (head <= tail)
        {
            if (gao[head] == b)
            {
                printf("%lld\n", gaogao[head]);
                wa = true;
                break;
            }
            rep(i, 10)
            {
                next = gao[head] % 1000 + i * 1000;
                if (!not_prime[next] && !vis[next])
                {
                    vis[next] = true;
                    gao[++tail] = next;
                    gaogao[tail] = gaogao[head] + 1;
                }
            }
            rep(i, 10)
            {
                next = gao[head] % 100 + gao[head] / 1000 * 1000 + i * 100;
                if (!not_prime[next] && !vis[next])
                {
                    vis[next] = true;
                    gao[++tail] = next;
                    gaogao[tail] = gaogao[head] + 1;
                }
            }
            rep(i, 10)
            {
                next = gao[head] % 10 + gao[head] / 100 * 100 + i * 10;
                if (!not_prime[next] && !vis[next])
                {
                    vis[next] = true;
                    gao[++tail] = next;
                    gaogao[tail] = gaogao[head] + 1;
                }
            }
            rep(i, 10)
            {
                next = gao[head] / 10 * 10 + i;
                if (!not_prime[next] && !vis[next])
                {
                    vis[next] = true;
                    gao[++tail] = next;
                    gaogao[tail] = gaogao[head] + 1;
                }
            }
            head++;
        }
        if (!wa) puts("Impossible");
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

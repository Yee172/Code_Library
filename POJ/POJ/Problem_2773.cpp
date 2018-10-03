#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <time.h>
#include <vector>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <complex>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
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
#define square(x) ((x) * (x))

namespace euler_sieve
{
    typedef int TYPE;
    const TYPE MAXN = 10050;
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
using euler_sieve::cnt;

bool sieve[1000050];
int selected[1000050];
int s_cnt;

int main()
{
    euler_sieve::euler_sieve();
    int n, m, k;
    while (~scanf("%d%d", &m, &k))
    {
        n = m;
        s_cnt = 0;
        memset(sieve, 0, sizeof(bool) * (m + 5));
        for (int i = 0; i < cnt && square(prime[i]) <= n; ++i)
        {
            if (n % prime[i] == 0)
            {
                while (n % prime[i] == 0) n /= prime[i];
                for (int j = prime[i]; j < m; j += prime[i]) sieve[j] = true;
            }
        }
        if (n > 1) for (int j = n; j < m; j += n) sieve[j] = true;
        for (int i = 1; i < m; ++i) if (!sieve[i]) selected[s_cnt++] = i;
        printf("%d\n", s_cnt ? (k - 1) / s_cnt * m + selected[(k - 1) % s_cnt] : k);
    }
    return 0;
}

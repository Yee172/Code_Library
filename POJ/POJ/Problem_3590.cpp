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

const int MAXN = 105;
vector<int> factor_plan[MAXN];
int max_lcm[MAXN];
int prime[MAXN];
int cnt;
bool vis[MAXN];
int res[MAXN];
int maximum;
int now;

void dfs(int i, int remain)
{
    if (remain < 0 || i >= cnt) return;
    if (prime[i] <= remain) dfs(i + 1, remain);
    int p = prime[i], tmp = now;
    for (; p <= remain; p *= prime[i])
    {
        now *= p;
        dfs(i + 1, remain - p);
        maximum = maximum < now ? now : maximum;
        now = tmp;
    }
}

int main()
{
    int t, n, p, q;
    vis[0] = vis[1] = true;
    for (int i = 2; i < MAXN; ++i)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < MAXN && i * prime[j] < MAXN; ++j)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i < MAXN; ++i)
    {
        maximum = 1;
        now = 1;
        dfs(0, i);
        max_lcm[i] = maximum;
        now = i;
        for (int j = 0; j < cnt && maximum > 1; ++j)
        {
            q = 1;
            while (maximum % prime[j] == 0) q *= prime[j], maximum /= prime[j];
            if (q > 1) now -= q, factor_plan[i].push_back(q);
        }
        while (now--) factor_plan[i].push_back(1);
        sort(factor_plan[i].begin(), factor_plan[i].end());
    }
    for (scanf("%d", &t); t--; )
    {
        scanf("%d", &n);
        p = 1;
        for (int i = 0; i < factor_plan[n].size(); ++i)
        {
            res[p + factor_plan[n][i] - 1] = p;
            for (int j = 1; j < factor_plan[n][i]; ++j)
                res[p] = p + 1, ++p;
            ++p;
        }
        printf("%d ", max_lcm[n]);
        for (int i = 1; i <= n; ++i) printf("%d%c", res[i], " \n"[i == n]);
    }
    return 0;
}

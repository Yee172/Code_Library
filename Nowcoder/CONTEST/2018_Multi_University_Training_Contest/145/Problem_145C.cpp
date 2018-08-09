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

vector<vector<int> > gao;
char buffer[1 << 20];
int n;
int res;

vector<vector<int> > dp;
inline void prepare(int k)
{
    int p = 1 << k, l, r;
    dp[k].resize(1 << p);
    rep(i, 1 << p)
    {
        l = r = 0;
        for (int j = 1 << p - 1; j; j >>= 2) l = (l << 1) | (j & i ? 1 : 0);
        for (int j = 1 << p - 2; j; j >>= 2) r = (r << 1) | (j & i ? 1 : 0);
        dp[k][i] = dp[k - 1][l & r] + dp[k - 1][l | r] + dp[k - 1][l ^ r];
    }
}

void dfs(const int i)
{
    if (i < 5)
    {
        int tmp = 0;
        for (auto each : gao[i]) tmp = tmp << 1 | each;
        res += dp[i][tmp];
        return;
    }
    for (int j = 0; j < (1 << i); j += 2) gao[i - 1][j / 2] = gao[i][j] & gao[i][j | 1];
    dfs(i - 1);
    for (int j = 0; j < (1 << i); j += 2) gao[i - 1][j / 2] = gao[i][j] | gao[i][j | 1];
    dfs(i - 1);
    for (int j = 0; j < (1 << i); j += 2) gao[i - 1][j / 2] = gao[i][j] ^ gao[i][j | 1];
    dfs(i - 1);
}

void Main()
{
    dp.resize(5);
    dp[0].resize(2);
    dp[0][0] = 0, dp[0][1] = 1;
    _rep(i, 4) prepare(i);
    scanf("%d", &n);
    res = 0;
    gao.resize(n + 1);
    _rep(i, n) gao[i].resize(1 << i);
    scanf("%s", buffer);
    rep(i, 1 << n) gao[n][i] = buffer[i] == '1';
    dfs(n);
    printf("%d\n", res);
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

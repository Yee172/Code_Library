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

int dp[8][2], digit[8];

int dfs(int position, bool last_is_six, bool up_limit)
{
    if (position < 0) return 1;
    if (!up_limit && dp[position][last_is_six] != -1) return dp[position][last_is_six];
    int res = 0;
    for (int i = 0, up_bound = up_limit ? digit[position] : 9; i <= up_bound; ++i)
    {
        if (i == 4 || (last_is_six && i == 2)) continue;
        res += dfs(position - 1, i == 6, up_limit && i == up_bound);
    }
    if (!up_limit) dp[position][last_is_six] = res;
    return res;
}

int cal(int x)
{
    int cnt = -1;
    while (x)
    {
        digit[++cnt] = x - x / 10 * 10;
        x /= 10;
    }
    return dfs(cnt, false, true);
}

int main()
{
    int n, m;
    memset(dp, -1, sizeof dp);
    while (~scanf("%d%d", &n, &m) && (n || m)) printf("%d\n", cal(m) - cal(n - 1));
    return 0;
}

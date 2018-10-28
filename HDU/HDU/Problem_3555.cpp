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

ll dp[25][2];
int digit[25];
const ll digit_max[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999,
                        999999999ll, 9999999999ll, 99999999999ll, 999999999999ll,
                        9999999999999ll, 99999999999999ll, 999999999999999ll,
                        9999999999999999ll, 99999999999999999ll, 999999999999999999ll};

ll dfs(int position, bool last_four, bool up_limit, bool have_counted)
{
    ll res = 0;
    if (have_counted)
    {
        if (!up_limit) res = digit_max[position + 1];
        else for (int i = position; i >= 0; --i) res = res * 10 + digit[i];
        return res + 1;
    }
    if (position < 0) return 0;
    if (!up_limit && dp[position][last_four] != -1) return dp[position][last_four];
    for (int i = 0, up_bound = up_limit ? digit[position] : 9; i <= up_bound; ++i)
        res += dfs(position - 1, i == 4, up_limit && i == up_bound, last_four && i == 9);
    if (!up_limit) dp[position][last_four] = res;
    return res;
}

ll cal(ll x)
{
    int cnt = -1;
    while (x)
    {
        digit[++cnt] = (int) (x - x / 10 * 10);
        x /= 10;
    }
    return dfs(cnt, false, true, false);
}

int main()
{
    int t;
    ll n;
    memset(dp, -1, sizeof dp);
    for (scanf("%d", &t); t--; ) scanf("%lld", &n), printf("%lld\n", cal(n));
    return 0;
}

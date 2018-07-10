#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define MAXN 10500
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
int t, n, s, m[105];
double P, p[105], dp[MAXN];


namespace Vince
{
    int solve(int _)
    {
        cin >> P >> n;
        P = 1.0 - P;
        s = 0;
        rep(i, 1, n)
        {
            cin >> m[i] >> p[i];
            p[i] = 1.0 - p[i];
            s += m[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        rep(i, 1, n) per(j, m[i], s) dp[j] = max(dp[j], dp[j - m[i]] * p[i]);
        per(i, 0, s) if (dp[i] >= P) return printf("Case %d: %d\n", _, i);
    }
}


int main()
{
    FAST;
    cin >> t;
    rep(_, 1, t)
    {
        Vince::solve(_);
    }
    return 0;
}
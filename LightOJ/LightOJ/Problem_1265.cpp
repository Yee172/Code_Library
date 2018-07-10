#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define MAXN 100500
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
double p;
int T, d, t;

namespace Vince
{
    double solve()
    {
        p = 1;
        scanf("%d%d", &t, &d);
        if (t & 1) return 0;
        while (t) p *= (t - 1) * 1.0 / (t + 1), t -= 2;
        return p;
    }
}


using namespace Vince;
int main()
{
    FAST;
    scanf("%d", &T);
    rep(_, 1, T)
    {
        printf("Case %d: %.12f\n", _, solve());
    }
    return 0;
}

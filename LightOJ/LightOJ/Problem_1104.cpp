#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define MAXN 100500
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
double p;
int n, t;

namespace Vince
{
    int solve()
    {
        p = 1;
        scanf("%d", &n);
        rep(i, 0, n)
        {
            p *= (n - i) * 1.0 / n;
            if (p <= .5) return i;
        }
    }
}


using namespace Vince;
int main()
{
    scanf("%d", &t);
    rep(_, 1, t)
    {
        printf("Case %d: %d\n", _, solve());
    }
    return 0;
}
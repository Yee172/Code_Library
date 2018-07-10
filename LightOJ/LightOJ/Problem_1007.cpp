#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define MAXN 5000500
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
int T;
int a, b;
ull r[MAXN];

namespace Vince
{
    ull solve()
    {
        scanf("%d%d", &a, &b);
        return r[b] - r[a - 1];
    }
}

using namespace Vince;
int main()
{
    r[1] = 1;
    for (ull i = 2; i <= 5000000; i++) if (!r[i]) for (ull j = i; j <= 5000000; j += i) r[j] = (r[j] ? r[j] : j) / i * (i - 1);
    rep(i, 1, 5000000) r[i] = r[i - 1] + r[i] * r[i];
    scanf("%d", &T);
    rep(_, 1, T) printf("Case %d: %llu\n", _, solve());
    return 0;
}

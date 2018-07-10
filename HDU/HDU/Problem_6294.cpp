#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define MAXN 1000500
char Vince[MAXN];
bool leq[MAXN];

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

void solve(ll n)
{
    scanf("%s", Vince);
    leq[n - 1] = false;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (Vince[i] == Vince[i + 1]) leq[i] = leq[i + 1];
        else leq[i] = Vince[i] < Vince[i + 1];
    }
    rep(i, n - 1) putchar(leq[i] ? '<' : '>');
    puts("");
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t, n;
    scanf("%lld", &t);
    while (t--) scanf("%lld", &n), solve(n);
    return 0;
}

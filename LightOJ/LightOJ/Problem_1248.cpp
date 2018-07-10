#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define rep(i, a, n) for (int i = a; i <= n; i++)
int t, n;
double r;


int main()
{
    FAST;
    cin >> t;
    rep(_, 1, t)
    {
        cin >> n;
        r = 0;
        rep(i, 1, n) r += n * 1.0 / i;
        printf("Case %d: %.12f\n", _, r);
    }
    return 0;
}

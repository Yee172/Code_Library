#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
typedef long long ll;
const ll MAXN = 500005;
ll n, R, k, x, l, r, m, a[MAXN], b[MAXN];

int f(ll x, ll k, ll m)
{
    rep(i, 0, n) b[i] = a[i];
    rep(i, 0, n)
    {
        if (i + R < n) x += b[i + R];
        if (i - R > 0) x -= b[i - R - 1];
        ll d = m - x;
        if (d > 0)
        {
            k -= d;
            b[min(i + R, n - 1)] += d;
            x = m;
            if (k < 0) return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> R >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, R) x += a[i];
    l = 0;
    r = 2e18;
    while (l < r)
    {
        m = l + (r + 1 - l >> 1);
        f(x, k, m) ? l = m : r = m - 1;
    }
    cout << r << endl;
    return 0;
}

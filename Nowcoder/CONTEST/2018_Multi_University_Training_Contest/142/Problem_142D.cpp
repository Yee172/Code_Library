#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.h"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

template <typename T>
inline T square(const T x) { return x * x; }
inline int sign(const int x) { return x < 0 ? -1 : x > 0; }
const double eps = 1e-8;
inline int sign(const double x) { return x < -eps ? -1 : x > eps; }

int a[205][205];

void Main()
{
    ll t;
    scanf("%lld", &t);
    ll n;
    while (t--)
    {
        scanf("%lld", &n);
        if (n == 0 || n & 1) puts("impossible");
        else
        {
            puts("possible");
            ll k = n / 2;
            rep(i, n) rep(j, k) a[i][j] = -1, a[i][j + k] = 1;
            rep(i, k) rep(j, i + 1) a[i + k][k - j - 1] = 0;
            rep(i, k - 1) rep(j, i + 1) a[i + 1][n - 2 - j] = 0;
            rep(i, n) rep(j, n) printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

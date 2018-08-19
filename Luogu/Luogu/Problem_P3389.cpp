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

namespace Gaussian_elimination
{
    const double eps = 1e-8;
    const int MAXN = 500;
    double a[MAXN][MAXN];
    int n = 0;

    inline int sign(const double x) { return x < -eps ? -1 : x > eps; }

    bool Gaussian_elimination()
    {
        int r;
        double f;
        for (int i = 0; i < n; ++i)
        {
            r = i;
            for (int j = i + 1; j < n; ++j) if (sign(fabs(a[j][i]) - fabs(a[r][i])) == 1) r = j;
            if (sign(a[r][i]) == 0) return false;
            if (r != i) for (int j = 0; j <= n; ++j) swap(a[r][j], a[i][j]);
            for (int k = i + 1; k < n; ++k)
            {
                f = a[k][i] / a[i][i];
                for (int j = i; j <= n; ++j) a[k][j] -= f * a[i][j];
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j) a[i][n] -= a[j][n] * a[i][j];
            a[i][n] /= a[i][i];
        }
        return true;
    }
}
using Gaussian_elimination::n;
using Gaussian_elimination::a;

int main()
{
    scanf("%d", &n);
    rep (i, n) rep(j, n + 1) scanf("%lf", &a[i][j]);
    bool p = Gaussian_elimination::Gaussian_elimination();
    if (p) rep(i, n) printf("%.2f\n", a[i][n]);
    else puts("No Solution");
    return 0;
}

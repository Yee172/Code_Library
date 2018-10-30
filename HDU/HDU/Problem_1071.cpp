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

typedef double db;
db p[3][2];

namespace Gaussian_elimination
{
    const double eps = 1e-8;
    vector<vector<double> > a;
    int n = 0;
    int augment_dimension = 1;

    inline void initialize() { a.assign((unsigned long)n, vector<double>(n + augment_dimension, 0)); }

    inline int sign(const double x) { return x < -eps ? -1 : x > eps; }

    bool Gaussian_elimination()
    {
        assert(n > 0);
        int r;
        double f;
        for (int i = 0; i < n; ++i)
        {
            r = i;
            for (int j = i + 1; j < n; ++j) if (sign(fabs(a[j][i]) - fabs(a[r][i])) == 1) r = j;
            if (sign(a[r][i]) == 0) return false;
            if (r != i) for (int j = 0; j < n + augment_dimension; ++j) swap(a[r][j], a[i][j]);
            for (int k = i + 1; k < n; ++k)
            {
                f = a[k][i] / a[i][i];
                for (int j = i; j < n + augment_dimension; ++j) a[k][j] -= f * a[i][j];
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
                for (int k = n; k < n + augment_dimension; ++k)
                    a[i][k] -= a[j][k] * a[i][j];
            for (int k = n; k < n + augment_dimension; ++k)
                a[i][k] /= a[i][i];
        }
        return true;
    }
}
using Gaussian_elimination::a;
using Gaussian_elimination::n;

int main()
{
    int t;
    db q, w, e;
    for (scanf("%d", &t); t--; )
    {
        rep(i, 3) scanf("%lf%lf", &p[i][0], &p[i][1]);
        n = 3;
        Gaussian_elimination::initialize();
        rep(i, 3) a[i][0] = p[i][0] * p[i][0], a[i][1] = p[i][0], a[i][2] = 1.0, a[i][3] = p[i][1];
        Gaussian_elimination::Gaussian_elimination();
        q = a[0][3], w = a[1][3], e = a[2][3];
        n = 2;
        Gaussian_elimination::initialize();
        rep(i, 2) a[i][0] = p[i + 1][0], a[i][1] = 1.0, a[i][2] = p[i + 1][1];
        Gaussian_elimination::Gaussian_elimination();
        w -= a[0][2], e -= a[1][2];
        printf("%.2f\n", (p[2][0] - p[1][0]) * (q * (p[1][0] * p[1][0] + p[1][0] * p[2][0] + p[2][0] * p[2][0]) / 3 + w * (p[1][0] + p[2][0]) / 2 + e));
    }
    return 0;
}

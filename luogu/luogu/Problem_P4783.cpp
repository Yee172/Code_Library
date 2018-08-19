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
    const int MOD = 0x3b9aca07;

    inline int __sub__(int a, const int b) { a -= b; return a < 0 ? a + MOD : a; }
    inline int __mul__(long long a, const int b) { a *= b; return (int) (a < MOD ? a : a - a / MOD * MOD); }
    inline int __pow__(int a, long long b) { int r = 1; for (; b; b >>= 1, a = __mul__(a, a)) { if (b & 1) r = __mul__(r, a); } return r; }

    vector<vector<int> > a;
    vector<int> diagonal;
    int n = 0;
    int augment_dimension = 1;

    inline void initialize()
    {
        a.resize((unsigned long)n, vector<int>(n + augment_dimension, 0));
        diagonal.resize((unsigned long)n, 0);
    }

    bool Gaussian_elimination()
    {
        assert(n > 0);
        int r;
        int f;
        for (int i = 0; i < n; ++i)
        {
            r = i;
            for (int j = i + 1; j < n; ++j) if (a[j][i] > a[r][i]) r = j;
            if (a[r][i] == 0) return false;
            if (r != i) for (int j = 0; j < n + augment_dimension; ++j) swap(a[r][j], a[i][j]);
            diagonal[i] = __pow__(a[i][i], MOD - 2);
            for (int k = i + 1; k < n; ++k)
            {
                f = __mul__(a[k][i], diagonal[i]);
                for (int j = i; j < n + augment_dimension; ++j) a[k][j] = __sub__(a[k][j], __mul__(f, a[i][j]));
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
                for (int k = n; k < n + augment_dimension; ++k)
                    a[i][k] = __sub__(a[i][k], __mul__(a[j][k], a[i][j]));
            for (int k = n; k < n + augment_dimension; ++k)
                a[i][k] = __mul__(a[i][k], diagonal[i]);
        }
        return true;
    }
}
using Gaussian_elimination::n;
using Gaussian_elimination::augment_dimension;
using Gaussian_elimination::a;

int main()
{
    scanf("%d", &n);
    augment_dimension = n;
    Gaussian_elimination::initialize();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < augment_dimension; ++i) a[i][n + i] = 1;
    bool p = Gaussian_elimination::Gaussian_elimination();
    if (p)
        for (int i = 0; i < n; ++i)
            for (int j = n; j < n + augment_dimension; ++j)
                printf("%d%c", a[i][j], " \n"[j == n + augment_dimension - 1]);
    else puts("No Solution");
    return 0;
}

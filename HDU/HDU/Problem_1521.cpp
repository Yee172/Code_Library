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

int n, m, f;
int a[20];
int fac[20];
double ifac[20];
double b[2][20];

int main()
{
    fac[0] = 1;
    ifac[0] = 1;
    _rep(i, 10) ifac[i] = ifac[i - 1] / i, fac[i] = fac[i - 1] * i;
    while (~scanf("%d%d", &n, &m))
    {
        rep(i, n) scanf("%d", a + i);
        b[0][0] = 1;
        _rep(i, m) b[0][i] = 0;
        f = 0;
        rep(i, n)
        {
            f ^= 1;
            for (int j = 0; j <= m; ++j) b[f][j] = 0;
            for (int k = 0; k <= m; ++k)
                if (abs(b[f ^ 1][k]) > 1e-6)
                    for (int j = 0, up = m - k; j <= up && j <= a[i]; ++j)
                        b[f][k + j] += b[f ^ 1][k] * ifac[j];
        }
        printf("%.0f\n", b[f][m] * fac[m]);
    }
    return 0;
}

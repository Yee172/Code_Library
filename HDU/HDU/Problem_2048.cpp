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

ll d[25];
ll f[25];

int main()
{
    d[0] = f[0] = f[1] = 1, d[1] = 0;
    for (int i = 2; i < 21; ++i) d[i] = (d[i - 1] + d[i - 2]) * (i - 1), f[i] = i * f[i - 1];
    int t, n;
    for (scanf("%d", &t); t--; ) scanf("%d", &n), printf("%.2f%%\n", (double) d[n] * 100 / f[n]);
    return 0;
}

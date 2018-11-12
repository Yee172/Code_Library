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

int a[1005][1005];
int n, k;

int main()
{
    int t, p;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &n, &k);
        if (n & 1 || k >= n)
        {
            puts("Impossible");
            continue;
        }
        p = 1;
        for (int i = 1; i <= n; ++i) a[1][i] = i;
        for (p <<= 1; n % p == 0; p <<= 1)
            for (int j = p / 2 + 1; j <= p; ++j)
                for (int k = 0; k * p < n; ++k)
                    for (int i = 1; i <= p; ++i)
                        a[j][p * k + i] = a[p + 1 - j][p * (k + 1) - i + 1];
        p >>= 1;
        if (k < p)
        {
            for (int i = 2; i <= k + 1; ++i)
                for (int j = 1; j <= n; ++j)
                    printf("%d%c", a[i][j], j == n ? '\n' : ' ');
        }
        else puts("Impossible");
    }
    return 0;
}

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

int binomial[20][20];
int a[10];
int b[10];

inline int __cal__(int k)
{
    int n = 0;
    int res = 1;
    _rep(i, 6)
    {
        if (b[i] % k == 0) b[i] /= k, n += b[i];
        else return 0;
    }
    _rep(i, 6)
    {
        res *= binomial[n][b[i]];
        n -= b[i];
    }
    return res;
}

int main()
{
    rep(i, 20) binomial[i][0] = binomial[i][i] = 1;
    for (int i = 2; i < 20; ++i)
        for (int j = 1; j < i; ++j)
            binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
    int t, x, res;
    for (scanf("%d", &t); t--; )
    {
        memset(a, 0, sizeof a);
        rep(i, 12) scanf("%d", &x), ++a[x];
        res = 0;
        memcpy(b, a, sizeof a);
        res += __cal__(1);
        memcpy(b, a, sizeof a);
        res += 8 * __cal__(3);
        memcpy(b, a, sizeof a);
        res += 6 * __cal__(4);
        memcpy(b, a, sizeof a);
        res += 3 * __cal__(2);
        _rep(i, 6) _rep(j, 6)
            {
                memcpy(b, a, sizeof a);
                --b[i], --b[j];
                if (b[i] < 0 || b[j] < 0) continue;
                res += 6 * __cal__(2);
            }
        printf("%d\n", res / 24);
    }
    return 0;
}

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
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (ll (i) = 1; (i) <= (n); ++(i))

namespace Manhattan_distance
{
    typedef long long TYPE;
    template <typename T> inline T get_min(const T a, const T b) { return a < b ? a : b; }
    template <typename T> inline T get_max(const T a, const T b) { return a > b ? a : b; }
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    const int inf = 0x3f3f3f3f;
    const int MAXN = 100050;
    const int MAX_DIMENSION = 10;
    int na = 0;
    int nb = 0;
    int dimension = 0;

    TYPE a[MAXN][MAX_DIMENSION];
    TYPE b[MAXN][MAX_DIMENSION];

    TYPE get_maximum_distance()
    {
        assert(na > 0);
        assert(nb > 0);
        assert(dimension > 0);

        TYPE maximum_a, minimum_a, maximum_b, minimum_b;
        TYPE res = 0, tmp;

        for (int s = 0, us = 1 << dimension; s < us; ++s)
        {
            minimum_a = minimum_b = INF;
            maximum_a = maximum_b = -INF;
            for (int i = 0; i < na; ++i)
            {
                tmp = 0;
                for (int j = 0, k = 1; j < dimension; ++j, k <<= 1)
                {
                    if (s & k) tmp += a[i][j];
                    else tmp -= a[i][j];
                }
                minimum_a = get_min(minimum_a, tmp);
                maximum_a = get_max(maximum_a, tmp);
            }
            for (int i = 0; i < nb; ++i)
            {
                tmp = 0;
                for (int j = 0, k = 1; j < dimension; ++j, k <<= 1)
                {
                    if (s & k) tmp += b[i][j];
                    else tmp -= b[i][j];
                }
                minimum_b = get_min(minimum_b, tmp);
                maximum_b = get_max(maximum_b, tmp);
            }
            res = get_max(res, get_max(maximum_a - minimum_b, maximum_b - minimum_a));
        }
        return res;
    }
}
using Manhattan_distance::get_maximum_distance;

int main()
{
    int t, n, m, k;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d%d", &n, &m, &k);
        ++k;
        Manhattan_distance::na = n;
        Manhattan_distance::nb = m;
        Manhattan_distance::dimension = k;
        rep(i, n) rep(j, k) scanf("%lld", &Manhattan_distance::a[i][j]);
        rep(i, m) rep(j, k) scanf("%lld", &Manhattan_distance::b[i][j]);
        rep(i, n) Manhattan_distance::a[i][0] = -Manhattan_distance::a[i][0];
        printf("%lld\n", Manhattan_distance::get_maximum_distance());
    }
    return 0;
}

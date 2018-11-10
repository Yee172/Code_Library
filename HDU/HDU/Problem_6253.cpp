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

int main()
{
    int t, cas;
    unsigned long long n;
    for (scanf("%d", &t), cas = 1; t--; ++cas)
    {
        scanf("%llu", &n);
        printf("Case #%d: %llu\n", cas, (n == 0 ? 1 : n == 1 ? 9 : n == 2 ? 41 : n == 3 ? 109 : (n - 5) * (n - 6) / 2 * 205 - (n - 4) * (n - 6) * 325 + (n - 4) * (n - 5) / 2 * 473));
    }
    return 0;
}

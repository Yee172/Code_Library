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
    int t, n;
    ll a, sum, maximum;
    for (scanf("%d", &t); t--; )
    {
        sum = 0;
        maximum = 0;
        scanf("%d", &n);
        rep(i, n) scanf("%lld", &a), sum += a, maximum = a > maximum ? a : maximum;
        puts(sum - maximum >= maximum - 1 ? "Yes" : "No");
    }
    return 0;
}

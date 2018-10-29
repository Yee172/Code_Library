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
    int n, m, p, q, g;
    while (~scanf("%d%d", &n, &m))
    {
        p = n * m;
        q = n + m;
        g = __gcd(p, q);
        printf("%d/%d\n", p / g, q / g);
    }
    return 0;
}

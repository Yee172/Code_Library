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

const double pi = acos(-1);

int main()
{
    int t;
    double r, h, d;
    for (scanf("%d", &t); t--; )
    {
        scanf("%lf%lf%lf", &r, &h, &d);
        printf("%.12f %.12f\n",
               r * r * pi * d * 2 + (r + d) * (r + d) * pi * h + 4 * pi * d * d * d / 3 + d * d * r * pi * pi,
               r * r * pi * 2 + 2 * (r + d) * pi * h + 4 * pi * d * d + 2 * d * r * pi * pi);
    }
    return 0;
}

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
typedef double db;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)

void Main()
{
    int t, m, R, x, y, r;
    for (scanf("%d", &t); t--; )
    {
        db res = 0;
        for (scanf("%d%d", &m, &R); m--; )
        {
            scanf("%d%d%d", &x, &y, &r);
            int H = x * x + y * y;
            if (H <= (R + r) * (R + r) && H >= (R - r) * (R - r))
            {
                db h = sqrt(H);
                res += acos((db)(r * r + H - R * R) / (h * 2 * r)) * r;
                res -= acos((db)(R * R + H - r * r) / (h * 2 * R)) * R;
            }
        }
        printf("%.12f\n", (res + acos(-1) * R) * 2);
    }

}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

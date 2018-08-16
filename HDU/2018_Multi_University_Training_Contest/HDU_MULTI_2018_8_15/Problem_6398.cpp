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
typedef long double db;
#define square(x) ((x) * (x))
const db PI = acosl(-1);
const db det = PI / 2 + 1e-8;

int x[3], y[3], w;
db area, side[3], height[3], angle[3];

#define get_distance(i, j) (sqrt(square(x[i] - x[j]) + square(y[i] - y[j])))
#define get_angle(i, j, k) (acos((square(side[i]) + square(side[j]) - square(side[k])) / (2 * side[i] * side[j])))

void Main()
{
    int t;
    for (scanf("%d", &t); t--; )
    {
        rep(i, 3) scanf("%d%d", x + i, y + i);
        scanf("%d", &w);
        db p = 0;
        rep(i, 3) p += (side[i] = get_distance(i, (i + 1) % 3));
        p /= 2;
        area = p;
        rep(i, 3) area *= (p - side[i]);
        area = sqrtl(area) * 2;
        rep(i, 3) height[i] = area / side[i];
        rep(i, 3) angle[i] = get_angle(i, (i + 1) % 3, (i + 2) % 3);
        db res = 1e9;
        rep(i, 3)
        {
            db a = side[i], b = side[(i + 1) % 3], c = side[(i + 2) % 3];
            db o_ab = angle[i], o_ac = angle[(i + 2) % 3];
            if (w >= a && w >= a - b * cos(o_ab) && w >= a - c * cos(o_ac)) res = min(res, height[i]);
            else
            {
                db theta = acos(w / a);
                db beta;
                db h = a * sin(theta);
                beta = theta + o_ab;
                if (beta < det && b * cos(beta) <= w) res = min(res, max(b * sin(beta), h));
                beta = theta - o_ab;
                if (beta >= 0 && b * cos(beta) <= w) res = min(res, h);
                beta = theta + o_ac;
                if (beta < det && c * cos(beta) <= w) res = min(res, max(c * sin(beta), h));
                beta = theta - o_ac;
                if (beta >= 0 && c * cos(beta) <= w) res = min(res, h);
            }
        }
        if (res == 1e9) puts("impossible");
        else printf("%.12f\n", (double) res);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

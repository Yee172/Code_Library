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

namespace geometry_2D
{
    template <typename T> inline T square(T a) { return a * a; }
    typedef double db;
    const db eps = 1e-8;
    inline int sign(db a) { return a < -eps ? -1 : a > eps; }
    template <typename T> inline T __abs__(T a) { return a > 0 ? a : -a; }

    class Vector
    {
    public:
        db x, y;
        Vector() : x(0), y(0) {}
        Vector(db x, db y) : x(x), y(y) {}
        template <typename T> inline Vector operator * (T c) const { return Vector{x * c, y * c}; }
        template <typename T> inline Vector &operator *= (T c) { x *= c, y *= c ;return *this; }
        inline db operator * (const Vector b) const { return x * b.x + y * b.y; } // dot product
        inline db operator ^ (const Vector &b) const { return x * b.y - b.x * y; } // cross product
    };

    class Point
    {
    public:
        db x, y;
        Point() : x(0), y(0) {}
        Point(db x, db y) : x(x), y(y) {}
        template <typename T> inline Point operator * (T c) { return Point{x * c, y * c}; }
        inline Vector operator - (const Point &b) const { return Vector{x - b.x, y - b.y}; }
    };

    inline db __dist_square__(Point p1, Point p2) { return square(p2.x - p1.x) + square(p2.y - p1.y); }
    inline db __dist__(Point p1, Point p2) { return sqrt(__dist_square__(p1, p2)); }
    inline Vector __vec__(Point from, Point to) { return Vector{to.x - from.x, to.y - from.y}; }
    inline db __dot__(Vector v1, Vector v2) { return v1.x * v2.x + v1.y * v2.y; }
    inline db __cross__(Vector v1, Vector v2) { return v1.x * v2.y - v2.x * v1.y; }
    inline db __area__(Point p1, Point p2, Point p3) { return __abs__((p2 - p1) ^ (p3 - p1)) / 2; }
}
using namespace geometry_2D;

int n, top;
Point p[50050];
Point hull[50050];

int cmp(const Point a, const Point b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }

void convex_hull()
{
    sort(p, p + n, cmp);
    top = 0;
    for (int i = 0; i < n; ++i)
    {
        for (; top > 1 && sign((p[i] - hull[top - 1]) ^ (hull[top - 2] - hull[top - 1])) <= 0; --top);
        hull[top++] = p[i];
    }
    int k = top;
    for (int i = n - 2; i >= 0; --i)
    {
        for (; top > k && sign((p[i] - hull[top - 1]) ^ (hull[top - 2] - hull[top - 1])) <= 0; --top);
        hull[top++] = p[i];
    }
    if (n > 1) --top;
}

int main()
{
    while (~scanf("%d", &n))
    {
        rep(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);
        convex_hull();
        db res = -1e20;
        for (int i = 0; i < top; ++i)
            for (int j = i + 1; j < top; ++j)
                for (int k = j + 1; k < top; ++k)
                    res = max(res, __area__(hull[i], hull[j], hull[k]));
        printf("%.2f\n", res);
    }
    return 0;
}

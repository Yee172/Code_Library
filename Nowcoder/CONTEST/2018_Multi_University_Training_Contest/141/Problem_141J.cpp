#include <bits/stdc++.h>
#pragma optimize("Ofast")

using namespace std;

void __LOCAL_TEST__()
{
    static int __INDEX__ = 0;
    static time_t __START__;
    static time_t __TEMP__;
    static time_t __END__;
    if (__INDEX__)
    {
        __END__ = clock();
        fprintf(stderr,
                "┏TIME CONSUMED BY STAGE %d: %.12f ms\n"
                "┗TOTAL TIME UNTIL STAGE %d: %.12f ms\n",
                __INDEX__,
                (__END__ - __TEMP__) / (double)CLOCKS_PER_SEC * 1000,
                __INDEX__,
                (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
        __TEMP__ = __END__;
        __INDEX__++;
    }
    else
    {
        freopen("../in.txt", "r", stdin);
        freopen("../out.txt", "w", stdout);
        __START__ = __TEMP__ = clock();
        __INDEX__++;
    }
}

#ifdef Yee_172
#define _______ __LOCAL_TEST__();
#else
#define _______ ;
#endif

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
template<typename T> inline T square(const T x) { return x * x; }
inline int sign(const int x) { return x < 0 ? -1 : x > 0; }
const double eps = 1e-8;
inline int sign(const double x) { return x < -eps ? -1 : x > eps; }

namespace geometry
{
    typedef long double db;
    inline int sign(const db x) { return x < -eps ? -1 : x > eps; }
    struct Point
    {
        db x,y;
        Point() { x = y = 0; }
        Point(db a,db b) : x(a), y(b) {}
        inline Point operator - (const Point &b) const
        { return Point(x - b.x, y - b.y); }
        inline Point operator + (const Point &b) const
        { return Point(x + b.x, y + b.y); }
        inline Point operator * (const db &b) const
        { return Point(x * b, y * b); }
        inline db dot(const Point &b) const
        { return x * b.x + y * b.y; }
        inline db cross(const Point &b,const Point &c) const
        { return (b.x - x) * (c.y - y) - (c.x - x) * (b.y - y); }
        inline db distance(const Point &b) const
        { return sqrt((*this - b).dot(*this - b)); }
        inline bool in_line(const Point &b, const Point &c) const
        { return !sign(cross(b,c)); }
        inline bool on_seg(const Point &b, const Point &c) const
        { return in_line(b, c) && (*this - c).dot(*this - b) < eps; }
    };

    typedef vector<Point> vp;

    inline db min(db a, db b)
    { return a < b ? a : b; }
    inline db max(db a, db b)
    { return a > b ? a : b; }
    inline db square(db x)
    { return x * x; }
    inline db square(const Point &p)
    { return p.dot(p); }
    Point line_cross(const Point &a, const Point &b, const Point &c, const Point &d)
    {
        db u = a.cross(b, c);
        db v = b.cross(a, d);
        return Point((c.x * v + d.x * u) / (u + v), (c.y * v + d.y * u) / (u + v));
    }

    db line_cross_circle(const Point &a, const Point &b, const Point &r, db R, Point &p1, Point &p2)
    {
        Point fp = line_cross(r, Point(r.x + a.y - b.y, r.y + b.x - a.x), a, b);
        db rtol = r.distance(fp);
        db rtos = fp.on_seg(a, b) ? rtol : min(r.distance(a) , r.distance(b));
        db atob = a.distance(b);
        db fptoe = sqrt(R * R - rtol * rtol) / atob;
        if( rtos > R - eps ) return rtos;
        p1 = fp + (a - b) * fptoe;
        p2 = fp + (b - a) * fptoe;
        return rtos;
    }

    db sector_area(const Point &r, const Point &a, const Point &b, db R)
    {
        db A2 = square(r - a);
        db B2 = square(r - b);
        db C2 = square(a - b);
        return square(R) * acos((A2 + B2 - C2) * 0.5 / sqrt(A2) / sqrt(B2)) * 0.5;
    }

    db TACIA(const Point &r, const Point &a, const Point &b, db R)
    {
        db adis = r.distance(a);
        db bdis = r.distance(b);
        if (adis < R + eps && bdis < R + eps) return r.cross(a , b) * 0.5;
        Point ta, tb;
        if (r.in_line(a, b)) return 0.0;
        db rtos = line_cross_circle(a, b, r, R, ta, tb);
        if (rtos > R - eps) return sector_area(r, a, b, R);
        if (adis < R + eps) return r.cross(a, tb) * 0.5 + sector_area(r, tb, b, R);
        if (bdis < R + eps) return r.cross(ta, b) * 0.5 + sector_area(r, a, ta, R);
        return r.cross(ta, tb) * 0.5 + sector_area(r, tb, b, R) + sector_area(r, a, ta, R);
    }

    vp p;

    db SPICA(int n, Point r, db R){
        int i;
        db ret = 0 , if_clock_t;
        for (i = 0 ; i < n ; i++)
        {
            if_clock_t = sign(r.cross(p[i], p[(i + 1) % n]));
            if (if_clock_t < 0) ret -= TACIA(r, p[(i + 1) % n], p[i], R);
            else ret += TACIA(r, p[i], p[(i + 1) % n], R);
        }
        return fabs(ret);
    }
}

signed main()
{
    _______
    int n;
    scanf("%d", &n);
    geometry::p.resize(n);
    rep(i, n) scanf("%Lf%Lf", &geometry::p[i].x, &geometry::p[i].y);
    long double tot = geometry::SPICA(n, geometry::p[0], 10000);
    int m;
    scanf("%d", &m);
    rep(i, m)
    {
        long double x, y;
        int p, q;
        scanf("%Lf%Lf%d%d", &x, &y, &p, &q);
        long double predict = tot * (q - p) / q;
        geometry::Point o(x, y);
        long double l = 0.0, r = 3000.0;
        while (geometry::sign(r - l) > 0)
        {
            long double mid = (l + r) / 2;
            if (geometry::sign(geometry::SPICA(n, o, mid) - predict) > 0) r = mid - eps;
            else l = mid;
        }
        printf("%.12Lf\n", l);
    }
    _______
    return 0;
}

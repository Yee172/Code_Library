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
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))
#define square(x) ((x) * (x))

namespace adaptive_Simpson_integral
{
    typedef double db;
    typedef pair<double, double> pdd;
    typedef pair<pdd, pdd> pdddd;
    const db eps = 1e-5;
    db (*f)(db);

    inline db simpson_formula(const db left, const db right)
    {
        db middle = (left + right) / 2.0;
        return (f(left) + 4.0 * f(middle) + f(right)) * (right - left) / 6.0;
    }

    inline db integral(const db left, const db right, db (*function)(double))
    {
        f = function;
        db res = 0, l, r, m, precision, S_total, S_left, S_right;
        queue<pdddd> q;
        q.push(make_pair(make_pair(left, right), make_pair(simpson_formula(left, right), eps)));
        while (!q.empty())
        {
            l = q.front().first.first;
            r = q.front().first.second;
            S_total = q.front().second.first;
            precision = q.front().second.second;
            q.pop();
            m = (l + r) / 2.0;
            S_left = simpson_formula(l, m);
            S_right = simpson_formula(m, r);
            if (fabs(S_left + S_right - S_total) <= 15.0 * precision)
                res += S_left + S_right + (S_left + S_right - S_total) / 15.0;
            else
            {
                q.push(make_pair(make_pair(l, m), make_pair(S_left, precision / 2.0)));
                q.push(make_pair(make_pair(m, r), make_pair(S_right, precision / 2.0)));
            }
        }
        return res;
    }
}
using adaptive_Simpson_integral::integral;

db _k, _a, l, r, m, value, res;
int k[99], a[99], b[99];
inline db f(db x) { return sqrt(square(2 * _k * (x - _a)) + 1); }
inline db F(db x, int i) { return k[i] * square(x - a[i]) + b[i]; }
inline vector<db> solve_equation(int a, int b, int c)
{
    vector<db> res;
    if (a == 0)
    {
        if (b == 0) return res;
        res.push_back(-1.0 * c / b);
        return res;
    }
    int delta = b * b - 4 * a * c;
    if (delta < 0) return res;
    if (delta == 0)
    {
        res.push_back(-1.0 * b / (2 * a));
        return res;
    }
    db sqrt_delta = sqrt(delta);
    res.push_back((-1.0 * b + sqrt_delta) / (2 * a));
    res.push_back((-1.0 * b - sqrt_delta) / (2 * a));
    return res;
}

int main()
{
    int t, n;
    for (scanf("%d", &t); t--; )
    {
        res = 0.0;
        vector<db> intersection(1, 0.0);
        scanf("%d", &n);
        rep(i, n) scanf("%d%d%d", k + i, a + i, b + i);
        rep(i, n)
        {
            db delta = sqrt((100.0 - b[i]) / k[i]);
            db intersection_point = (db)a[i] + delta;
            if (0 < intersection_point && intersection_point < 100) intersection.push_back(intersection_point);
            intersection_point = (db)a[i] - delta;
            if (0 < intersection_point && intersection_point < 100) intersection.push_back(intersection_point);
            for (int j = i + 1; j < n; ++j)
            {
                if (k[i] == k[j] && a[i] == a[j] && b[i] == b[j]) continue;
                for (auto solution :
                        solve_equation(k[i] - k[j],
                                       -2 * (a[i] * k[i] - a[j] * k[j]),
                                       a[i] * a[i] * k[i] - a[j] * a[j] * k[j] + b[i] - b[j]
                        ))
                    if (0 < solution && solution < 100 && F(solution, i) < 100) intersection.push_back(solution);
            }
        }
        sort(intersection.begin(), intersection.end());
        intersection.push_back(100.0);
        int length = (int)intersection.size();
        for (int i = 0; i < length - 1; ++i)
        {
            l = intersection[i], r = intersection[i + 1];
            m = (l + r) / 2;
            _k = _a = 0.0;
            value = 100.0;
            db tmp;
            rep(j, n)
            {
                tmp = F(m, j);
                if (tmp < value)
                {
                    value = tmp;
                    _k = k[j];
                    _a = a[j];
                }
            }
            res += integral(l, r, f);
        }
        printf("%.2f\n", res);
    }
    return 0;
}

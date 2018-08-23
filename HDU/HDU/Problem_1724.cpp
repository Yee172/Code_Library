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

namespace adaptive_Simpson_integral
{
    typedef double db;
    typedef pair<double, double> pdd;
    typedef pair<pdd, double> pddd;
    const db eps = 1e-5;
    int a, b;
    inline db f(const db x)
    {
        return sqrt(1 - x * x / a / a) * b;
    }

    inline db simpson_formula(const db left, const db right)
    {
        db middle = (left + right) / 2.0;
        return (f(left) + 4.0 * f(middle) + f(right)) * (right - left) / 6.0;
    }

    inline db integral(const db left, const db right)
    {
        db res = 0, l, r, m, precision, S_total, S_left, S_right;
        queue<pddd> q;
        q.push(make_pair(make_pair(left, right), eps));
        while (!q.empty())
        {
            l = q.front().first.first;
            r = q.front().first.second;
            precision = q.front().second;
            q.pop();
            m = (l + r) / 2.0;
            S_total = simpson_formula(l, r);
            S_left = simpson_formula(l, m);
            S_right = simpson_formula(m, r);
            if (fabs(S_left + S_right - S_total) <= 15.0 * precision)
                res += S_left + S_right + (S_left + S_right - S_total) / 15.0;
            else q.push(make_pair(make_pair(l, m), precision / 2.0)), q.push(make_pair(make_pair(m, r), precision / 2.0));
        }
        return res;
    }
}
using adaptive_Simpson_integral::a;
using adaptive_Simpson_integral::b;
using adaptive_Simpson_integral::integral;

int main()
{
    int t, l, r;
    double res;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d%d%d", &a, &b, &l, &r);
        l = l > -a ? l : -a;
        r = r < a ? r : a;
        res = integral(l, r) * 2;
        printf("%.3f\n", res);
    }
    return 0;
}

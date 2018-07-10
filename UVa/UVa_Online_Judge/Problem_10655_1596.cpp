#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 2

struct Matrix
{
    ll n;
    ll a[N][N];
    Matrix() {}
    Matrix(ll n) : n(n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
    }
    ll *operator[](int i)
    {
        return a[i];
    }
    Matrix operator*(Matrix &b) const
    {
        Matrix res(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                {
                    res[i][j] += a[i][k] * b[k][j];
                }
        return res;
    }
    Matrix operator^(ll t) const
    {
        Matrix res(n);
        for (int i = 0; i < n; i++)
            res[i][i] = 1;
        Matrix tmp = *this;
        while (t)
        {
            if (t & 1)
                res = res * tmp;
            t >>= 1;
            tmp = tmp * tmp;
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%lld%c", a[i][j], j == n - 1 ? '\n' : ' ');
    }
};

Matrix o = Matrix(2);

int solve(ll p, ll q)
{
    ll n;
    if (~scanf("%lld", &n))
    {
        o[0][0] = p; o[0][1] = -q;
        o[1][0] = 1;

        if (n == 0) return puts("2");
        Matrix res = o^(n - 1);
        return printf("%lld\n", res[0][0] * p + res[0][1] * 2);
    }
    return 0;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll p, q;
    while (~scanf("%lld%lld", &p, &q)) solve(p, q);
    return 0;
}

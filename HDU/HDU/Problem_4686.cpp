#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 0x3b9aca07
#define N 5

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
                    res[i][j] += a[i][k] * b[k][j] % mod;
                    res[i][j] %= mod;
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

Matrix o = Matrix(5);

void solve(ll n)
{
    ll a0, ax, ay, b0, bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &a0, &ax, &ay, &b0, &bx, &by);
    o.a[0][0] = ax * bx; o.a[0][1] = ax * by; o.a[0][2] = bx * ay; o.a[0][3] = ay * by; o.a[0][4] = a0 * b0;
                         o.a[1][1] = ax     ;                      o.a[1][3] = ay     ; o.a[1][4] = a0     ;
                                              o.a[2][2] = bx     ; o.a[2][3] = by     ; o.a[2][4] = b0     ;
                                                                 ; o.a[3][3] = 1      ; o.a[3][4] = 1      ;
                                                                                      ; o.a[4][4] = 1      ;
    for (ll i = 0; i < 5; i++)
        for (ll j = 0; j < 5; j++)
            o.a[i][j] %= mod;
    Matrix ans = o^n;
    printf("%lld\n", ans[0][4]);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll n;
    while (~scanf("%lld", &n)) solve(n);
    return 0;
}

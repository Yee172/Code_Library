#include <bits/stdc++.h>
#define Vince std
using namespace Vince;
typedef long long ll;
#define N 2
#define mod 0x3b9aca07
ll powmod(ll a,ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}

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
                    res[i][j] += a[i][k] * b[k][j] % (mod - 1);
                    res[i][j] %= mod - 1;
                }
        return res;
    }
    Matrix operator^(ll t) const
    {
        Matrix res(n);
        for (int i = 0; i < n; i++)
            res[i][i] = 1;
        Matrix tmp = *this;
        for (; t; t >>= 1)
        {
            if (t & 1) res = res * tmp;
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

ll a, b, n;
Matrix o = Matrix(2);

int solve(ll a, ll b, ll n)
{

    if (n == 0) return printf("%lld\n", a);
    if (n == 1) return printf("%lld\n", b);
    Matrix x = o^(n - 2);
    ll res = powmod(a, x.a[1][0] + x.a[1][1]) * powmod(b, x.a[0][0] + x.a[0][1]);
    return printf("%lld\n", res % mod);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    o.a[0][0] = 1;
    o.a[0][1] = 1;
    o.a[1][0] = 1;
    o.a[1][1] = 0;
    while (~scanf("%lld%lld%lld", &a, &b, &n)) solve(a, b, n);
    return 0;
}

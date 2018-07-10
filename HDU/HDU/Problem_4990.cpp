#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3;
ll mod;

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
Matrix o = Matrix(3);

void solve(ll n)
{
    Matrix ans = o^n;
    printf("%lld\n", ans.a[n & 1 ^ 1][2]);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    o.a[0][0] = 0; o.a[0][1] = 2; o.a[0][2] = 1;
    o.a[1][0] = 2; o.a[1][1] = 0; o.a[1][2] = 0;
    o.a[2][0] = 0; o.a[2][1] = 0; o.a[2][2] = 1;
    ll n;
    while (~scanf("%lld%lld", &n, &mod)) solve(n);
    return 0;
}

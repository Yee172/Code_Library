#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10
#define rep(i, n) for (ll i = 0; i < n; i++)
ll mod;

struct Matrix
{
    ll n;
    ll a[MAXN][MAXN];
    Matrix() {}
    Matrix(ll n): n(n)
    {
        init();
    }
    void init()
    {
        rep(i, n) rep(j, n) a[i][j] = 0;
    }
    ll* operator[](ll i)
    {
        return a[i];
    }
    Matrix operator*(Matrix &b) const
    {
        Matrix res(n);
        rep(i, n) rep(j, n) rep(k, n) res[i][j] += a[i][k] * b[k][j] % mod, res[i][j] %= mod;
        return res;
    }
    Matrix operator^(ll t) const
    {
        Matrix res(n);
        rep(i, n) res[i][i] = 1;
        Matrix temp = *this;
        while (t)
        {
            if (t & 1) res = res * temp;
            t >>= 1;
            temp = temp * temp;
        }
        return res;
    }
};

Matrix o(2);

int solve()
{
    ll a, b, n, m;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    if (n == 0) return printf("%lld\n", a);
    if (n == 1) return printf("%lld\n", b);
    mod = 1;
    rep(i, m) mod *= 10;
    Matrix M = o^(n - 1);
    return printf("%lld\n", (b * M[0][0] + a * M[0][1]) % mod);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    o[0][0] = o[0][1] = o[1][0] = 1;
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}

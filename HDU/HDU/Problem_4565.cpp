#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 2
#define rep(i, n) for (ll i = 0; i < n; i++)
ll mod;

struct Matrix
{
    ll n;
    ll a[N][N];
    Matrix() {}
    Matrix(ll n) : n(n)
    {
        init();
    }
    void init()
    {
        rep(i, n) rep(j, n) a[i][j] = 0;
    }
    ll *operator[](ll i)
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
};

void solve(ll a, ll b, ll n)
{
    Matrix o(2);
    o[0][0] = 2 * a % mod; o[0][1] = (b - a * a + mod) % mod;
    o[1][0] = 1;
    Matrix t = o^(n - 1);
    printf("%lld\n", ((t[0][0] * 2 * a + t[0][1] * 2) % mod + mod) % mod);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll a, b, n;
    while (~ scanf("%lld%lld%lld%lld", &a, &b, &n, &mod)) solve(a, b, n);
    return 0;
}

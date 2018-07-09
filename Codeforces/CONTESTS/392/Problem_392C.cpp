#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 85
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repp(i, a, n) for (ll i = a; i < n; i++)
#define mod 0x3b9aca07

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

ll yanghui[MAXN][MAXN];
void gao(ll n, ll k)
{
    ll l = k + 1;
    rep(i, l)
    {
        yanghui[i][0] = yanghui[i][i] = 1;
        repp(j, 1, i) yanghui[i][j] = (yanghui[i - 1][j] + yanghui[i - 1][j - 1]) % mod;
    }
    Matrix res(2 * k + 4);
    rep(i, k + 1) rep(j, k + 1) res[i][j] = res[i + k + 1][j] = res[i][j + k + 1] = yanghui[k - i][k - j];
    rep(i, k + 1) res[i][2 * k + 2] = res[i + k + 1][2 * k + 3] = 1;
    res[2 * k + 2][2 * k + 2] = res[2 * k + 3][2 * k + 3] = 1;
    Matrix ans = res^(n - 1);
    ll r = 0;
    rep(i, 2 * k + 4) r += ans[0][i], r %= mod;
    printf("%lld\n", r);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll n, k;
    scanf("%lld%lld", &n, &k);
    if (n == 1) return puts("1");
    gao(n, k);
    return 0;
}

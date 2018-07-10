#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define N 20
ll mod;
ll f[N];

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

struct Matrix
{
    bool cyclic = false;
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
        if (cyclic)
        {
            res.cyclic = true;
            rep(k, n) if (a[1][k]) rep(j, n) if (b[k][j]) res[1][j] += a[1][k] * b[k][j] % mod, res[1][j] %= mod;
            rep(i, n - 1)
            {
                res[i + 1][1] = res[i][n];
                rep(j, n - 1) res[i + 1][j + 1] = res[i][j];
            }
        }
        else rep(i, n) rep(j, n) rep(k, n) res[i][j] += a[i][k] * b[k][j] % mod, res[i][j] %= mod;
        return res;
    }
    Matrix operator^(ll t) const
    {
        Matrix res(n);
        res.cyclic = cyclic;
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


int solve(ll d, ll n)
{
    Matrix o(d);
    ll res = 0;
    rep(i, d) scanf("%lld", o[0] + i), o[0][i] %= mod;
    rep(i, d) scanf("%lld", f + i), f[i] %= mod;
    if (d >= n) return printf("%lld\n", f[n - 1]);
    rep(i, d - 1) o[i + 1][i] = 1;
    Matrix r = o^(n - d);
    rep(i, d) res += r[0][i] * f[d - i - 1], res %= mod;
    return printf("%lld\n", res);
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll d, n;
    while (~ scanf("%lld%lld%lld", &d, &n, &mod)) if (d) solve(d, n);
    return 0;
}

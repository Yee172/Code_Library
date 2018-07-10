#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 5
#define mod 987654321
#define rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

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

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

void solve(ll p)
{
    if (!p) return;
    if (p & 1 || p < 8) puts("0");
    else
    {
        Matrix o(2);
        o[1][1] = o[1][2] = o[2][1] = 1;
        Matrix r = o^(p - 4);
        printf("%lld\n", (r[1][1] - p / 2 + 1 + mod) % mod);
    }
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll p;
    while (~ scanf("%lld", &p)) solve(p);
    return 0;
}

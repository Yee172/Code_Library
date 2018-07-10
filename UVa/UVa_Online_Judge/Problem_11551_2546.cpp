#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 55
#define mod 1000
#define rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
ll a[N];

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

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

void solve(ll n, ll r)
{
    rep(i, n) scanf("%lld", a + i);
    Matrix o(n);
    ll x, b;
    rep(i, n)
    {
        scanf("%lld", &x);
        rep(j, x) scanf("%lld", &b), o[i][b + 1] = 1;
    }
    Matrix res = o^r;
    ll tmp;
    rep(i, n)
    {
        tmp = 0;
        rep(j, n) tmp += res[i][j] * a[j], tmp %= mod;
        printf("%lld%c", tmp, i == n ? '\n' : ' ');
    }
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t, n, r;
    scanf("%lld", &t);
    while (~ scanf("%lld%lld", &n, &r)) solve(n, r);
    return 0;
}

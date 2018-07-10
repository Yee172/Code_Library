#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

const ll m = 1LL << 32;
#define mod m

template <typename T>
class Matrix
{
#define ull unsigned long long
public:
    ull n;
    bool cyclic = false;
    vector<vector<T> > a;
    Matrix() {}
    Matrix(ull n) : n(n)
    {
        init();
    }
    vector<T> &operator[](ull i)
    {
        return a[i];
    }

    Matrix<T> operator*(Matrix &b) const
    {
        Matrix<T> res(n);
        if (cyclic)
        {
            res.cyclic = true;
            rep(k, n) if (a[0][k]) rep(j, n) if (b[k][j])
                        {
#ifdef mod
                            res[0][j] += a[0][k] * b[k][j] % mod, res[0][j] %= mod;
#else
                            res[0][j] += a[0][k] * b[k][j];
#endif
                        }
            rep(i, n - 1)
            {
                res[i + 1][0] = res[i][n - 1];
                rep(j, n - 1) res[i + 1][j + 1] = res[i][j];
            }
        }
        else rep(k, n) rep(i, n) if (a[i][k]) rep(j, n)
                        {
#ifdef mod
                            res[i][j] += a[i][k] * b[k][j] % mod, res[i][j] %= mod;
#else
                            res[i][j] += a[i][k] * b[k][j];
#endif
                        }
        return res;
    }

    Matrix<T> operator^(ull t) const
    {
        Matrix<T> res(n);
        res.cyclic = cyclic;
        rep(i, n) res[i][i] = 1;
        Matrix<T> tmp = *this;
        while (t)
        {
            if (t & 1) res = res * tmp;
            t >>= 1;
            tmp = tmp * tmp;
        }
        return res;
    };

    void print()
    {
        rep(i, n) rep(j, n) cout << a[i][j] << j == n - 1 ? '\n' : ' ';
    };

private:
    void init()
    {
        a = vector<vector<T> >(n, vector<T>(n, 0));
        rep(i, n) rep(j, n) a[i][j] = 0;
    };
#undef ull
};

#define square(x) ((x) * (x))
ll dp[30][10];
void solve()
{
    ll base, score;
    scanf("%lld%lld", &base, &score);
    dp[0][0] = 0;
    for (ll i = 1; i < base; i++) dp[0][i] = 1;
    for (ll i = 1; i < square(base - 1); i++)
        for (ll j = 0; j < base; j++)
        {
            dp[i][j] = 0;
            for (ll k = 1; k < base, i - k * k >= 0; k++)
            {
                if (j - k >= 0) dp[i][j] += dp[i - k * k][j - k];
                if (j + k < base) dp[i][j] += dp[i - k * k][j + k];
                dp[i][j] %= mod;
            }
        }
    Matrix<ll> o(square(base - 1) * base);
    rep(i, square(base - 1) * base - base) o[i][i + base] = 1;
    rep(i, base)
    {
        ll tmp = square(base - 1) * base - base + i;
        for (ll j = 1; j < base; j++)
            {
                if (i - j >= 0) o[tmp][tmp - j * j * base + base - j] = 1;
                if (i + j < base) o[tmp][tmp - j * j * base + base + j] = 1;
            }
    }
    Matrix<ll> r = o ^ score;
    ll res = 0;
    rep(i, square(base - 1) * base) rep(j, square(base - 1) * base) _debug("%lld%c", r[i][j], j == square(base - 1) * base - 1 ? '\n' : ' ')
    rep(i, base) rep(j, square(base - 1) * base) res += r[i][j] * dp[j / base][j % base] % mod + mod, res %= mod;
    printf("%lld\n", res);
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t;
    scanf("%lld", &t);
    _rep(_, t)
    {
        printf("Case %lld: ", _);
        solve();
    }
    return 0;
}

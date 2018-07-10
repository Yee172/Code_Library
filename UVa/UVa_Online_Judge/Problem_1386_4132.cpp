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

ll a[505];
ll m;
#define mod m

template <typename T>
class Matrix
{
public:
    ll n;
    bool cyclic = false;
    vector<vector<T> > a;
    Matrix(ll n) : n(n)
    {
        init();
    }
    vector<T> &operator[](ll i)
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
        else rep(i, n) rep(j, n) rep(k, n)
                    {
#ifdef mod
                        res[i][j] += a[i][k] * b[k][j] % mod, res[i][j] %= mod;
#else
                        res[i][j] += a[i][k] * b[k][j];
#endif
                    }
        return res;
    }

    Matrix<T> operator^(ll t) const
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
        a = vector<vector<T> >((unsigned long long) n, vector<T>((unsigned long long) n, 0));
        rep(i, n) rep(j, n) a[i][j] = 0;
    };
};

void solve(ll n, ll d, ll k)
{
    rep(i, n) scanf("%lld", a + i);
    Matrix<ll> o(n);
    o.cyclic = true;
    rep(i, n) rep(j, n) if (min(abs(i - j), n - abs(i - j)) <= d) o[i][j] = 1;
    Matrix<ll> r = o^k;
    ll tmp;
    rep(i, n)
    {
        tmp = 0;
        rep(j, n) tmp += r[i][j] * a[j] % m, tmp %= m;
        printf("%lld%c", tmp, i == n - 1 ? '\n' : ' ');
    }
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll n, d, k;
    while (~ scanf("%lld%lld%lld%lld", &n, &m, &d, &k)) solve(n, d, k);
    return 0;
}

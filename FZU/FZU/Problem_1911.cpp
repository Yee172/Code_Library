#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
typedef int ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

ll m, n;
#define mod m

template <typename T>
class Matrix
{
#define ull unsigned long long
public:
    ull n;
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
        rep(k, n) rep(i, n) if (a[i][k]) rep(j, n)
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

private:
    void init()
    {
        a = vector<vector<T> >(n, vector<T>(n, 0));
        rep(i, n) rep(j, n) a[i][j] = 0;
    };
#undef ull
};

ll a[205][205];
Matrix<ll> o(2);
void solve()
{
    scanf("%d%d", &n, &m);
    Matrix<ll> r = o ^ (n + 1);
    ll res = r[1][1] + m - 1;
    res %= m;
    if (res == 0 || res & 1) puts("No");
    else
    {
        puts("Yes");
        ll k = res / 2;
        rep(i, res) rep(j, k) a[i][j] = -1, a[i][j + k] = 1;
        rep(i, k) rep(j, i + 1) a[i + k][k - j - 1] = 0;
        rep(i, k - 1) rep(j, i + 1) a[i + 1][res - 2 - j] = 0;
        rep(i, res) rep(j, res) printf("%d%c", a[i][j], j == res - 1 ? '\n' : ' ');
    }
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    o[0][1] = o[1][0] = o[1][1] = 1;
    ll t;
    scanf("%d", &t);
    _rep(_, t) printf("Case %d: ", _), solve();
    return 0;
}

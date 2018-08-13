#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

#define MOD 0x3b9aca07

namespace matrix
{
    typedef unsigned long long ull;
    template <typename T>
    class Matrix
    {
    public:
        ull n;
        bool cyclic = false;
        vector<vector<T> > a;
        Matrix() {}
        Matrix(ull n) : n(n) { init(); }
        vector<T> &operator [] (ull i) { return a[i]; }
        Matrix<T> operator * (Matrix &b) const
        {
            Matrix<T> res(n);
            if (cyclic)
            {
                res.cyclic = true;
                for (int k = 0; k < n; k++)
                    if (a[0][k])
                        for (int j = 0; j < n; j++)
                            if (b[k][j])
                            {
#ifdef MOD
                                res[0][j] += a[0][k] * b[k][j] % MOD, res[0][j] %= MOD;
#else
                                res[0][j] += a[0][k] * b[k][j];
#endif
                            }
                for (int i  = 0; i < n - 1; i++)
                {
                    res[i + 1][0] = res[i][n - 1];
                    for (int j = 0; j < n - 1; j++) res[i + 1][j + 1] = res[i][j];
                }
            }
            else
                for (int k = 0; k < n; k++)
                    for (int i = 0; i < n; i++)
                        if (a[i][k])
                            for (int j = 0; j < n; j++)
                            {
#ifdef MOD
                                res[i][j] += a[i][k] * b[k][j] % MOD, res[i][j] %= MOD;
#else
                                res[i][j] += a[i][k] * b[k][j];
#endif
                            }
            return res;
        }

        Matrix<T> operator^(ull t) const
        {
            assert(n >= 0);
            Matrix<T> res(n);
            res.cyclic = cyclic;
            for (int i = 0; i < n; i++) res[i][i] = 1;
            Matrix<T> tmp = *this;
            for (; t; t >>= 1)
            {
                if (t & 1) res = res * tmp;
                tmp = tmp * tmp;
            }
            return res;
        };

        void print()
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cout << a[i][j] << " \n"[j == n - 1];
        };

    private:
        void init()
        {
            a = vector<vector<T> >(n, vector<T>(n, 0));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    a[i][j] = 0;
        };
    };
}

using matrix::Matrix;
int t;
ll a, b, c, d, p, n, tmp;
Matrix<ll> o(3);
void initial()
{
    o[1][0] = c;
    o[1][1] = d;
    o[0][1] = o[1][2] = o[2][2] = 1;
}

void Main()
{
    for (scanf("%d", &t); t; t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &p, &n);
        ll now = 3, gao, kexiao;
        while ((p / now) != (p / (now + 1)) && now <= n)
        {
            tmp = b;
            b = (a * c % MOD + b * d % MOD + p / now) % MOD;
            a = tmp;
            ++now;
        }
        initial();
        while (now <= n)
        {
            kexiao = p / now;
            if (kexiao) gao = min(p / kexiao, n);
            else gao = n;
            Matrix<ll> r = o^(gao - now + 1);
            (tmp = r[0][0] * a % MOD + r[0][1] * b % MOD + r[0][2] * kexiao % MOD) %= MOD;
            (b = r[1][0] * a % MOD + r[1][1] * b % MOD + r[1][2] * kexiao % MOD) %= MOD;
            a = tmp;
            now = gao;
            ++now;
        }
        printf("%lld\n", b);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

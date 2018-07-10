#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAXN 1050
#define MAXK 15
#define rep(i, n) for (ll i = 0; i < n; i++)
#define mod 6

struct Matrix
{
    ll n;
    ll a[MAXK][MAXK];
    Matrix() {}
    Matrix(ll n) : n(n)
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


ll A[MAXN][MAXK];
ll E[MAXN][MAXK];
ll B[MAXK][MAXN];
void solve(ll n, ll k)
{
    if (n == 0 && k == 0) return;
    Matrix M(k);
    rep(i, n) rep(j, k) scanf("%lld", A[i] + j);
    rep(i, k) rep(j, n) scanf("%lld", B[i] + j);
    rep(i, k) rep(j, k) rep(l, n) M[i][j] += B[i][l] * A[l][j], M[i][j] %= mod;
    Matrix C = M^(n * n - 1);
    memset(E, 0, sizeof E);
    rep(i, n) rep(j, k) rep(l, k) E[i][j] += A[i][l] * C[l][j], E[i][j] %= mod;
    ll res = 0, temp;
    rep(i, n) rep(j, n)
        {
            temp = 0;
            rep(l, k) temp += E[i][l] * B[l][j];
            res += temp % mod;
        }
    printf("%lld\n", res);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    ll n, k;
    while (~scanf("%lld%lld", &n, &k)) solve(n, k);
    return 0;
}

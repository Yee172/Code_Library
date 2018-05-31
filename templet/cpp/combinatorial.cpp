#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
#define mod 0x3b9aca07

const ll N = 205;
const ll M = 105;
ll binom[N][M];
void binom_init()
{
    rep(i, N) binom[i - 1][0] = 1;
    rep(i, N - 1) rep(j, M - 1) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
}

// stiring numbers of the second kind
#define MAXN 200050
ll powmod(ll a,ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}
ll modinv[MAXN];
ll fa_inv[MAXN];
ll f[] = {1, -1};

ll stirling_init()
{
    modinv[0] = 0, modinv[1] = 1;
    for (ll i = 2; i < MAXN; i++) modinv[i] = (mod - mod / i) * modinv[mod % i] % mod;
    fa_inv[0] = 1;
    for (ll i = 1; i < MAXN; i++) fa_inv[i] = fa_inv[i - 1] * modinv[i] % mod;
}

ll stirling(ll n, ll m)
{
    ll r = 0;
    if (n >= m)
        for (ll i = 0; i < m + 1; i++)
            r = (r + f[i & 1] * fa_inv[m - i] * fa_inv[i] % mod * powmod(m - i, n)) % mod;
    return r;
}

#include <bits/stdc++.h>
using namespace std;
#define MAXN 4050
#define mod 0x3b9aca07
typedef long long ll;
ll t, _;
ll i, j;
ll mul[MAXN];
ll dp[505][505];

vector<ll> prime;
bool vis[MAXN];
void euler_sieve()
{
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i);
        for (vector<ll>::iterator pr = prime.begin(); pr != prime.end(), i * *pr < MAXN; pr++)
        {
            vis[i * *pr] = 1;
            if (i % *pr == 0) break;
        }
    }
}

void gao()
{
    mul[0] = 1;
    for (i = 0; i <= 500; i++) dp[i][0] = 1;
    for (i = 1; i <= 500; i++)
    {
        for (j = 1; j <= 500; j++) dp[j][i] = (dp[j - 1][i] + prime[j - 1] * dp[j][i - 1]) % mod;
        mul[i] = mul[i - 1] * (prime[i - 1] - 1) % mod;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    euler_sieve();
    gao();
    for (_ = 1; _ <= t; _++)
    {
        ll k, p;
        printf("Case %lld: ", _);
        scanf("%lld%lld", &k, &p);
        printf("%lld\n", dp[p][k - p] * mul[p] % mod);
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10000050
vector<ll> prime;
bool vis[MAXN];
ll phi[MAXN];
ll sum[MAXN];
void euler_function_sieve()
{
    sum[1] = phi[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        if (!vis[i]) prime.push_back(i), phi[i] = i - 1;
        for (vector<ll>::iterator pr = prime.begin(); pr != prime.end(), i * *pr < MAXN; pr++)
        {
            vis[i * *pr] = 1;
            if (i % *pr == 0)
            {
                phi[i * *pr] = phi[i] * *pr;
                break;
            }
            else phi[i * *pr] = phi[i] * (*pr - 1);
        }
        sum[i] = sum[i - 1] + phi[i];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    euler_function_sieve();
    ll n;
    scanf("%lld", &n);
    ll res = 0;
    for (vector<ll>::iterator pr = prime.begin(); pr != prime.end(), *pr <= n; pr++)
        res += sum[n / *pr] * 2 - 1;
    printf("%lld\n", res);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

vector<ll> prime;
bool vis[MAXN];
ll phi[MAXN];
void euler_function_sieve()
{
    phi[1] = 1;
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
    }
}

int is_prime(ll n)
{
    if (n == 2 || n == 3) return 1;
    ll remain = n % 6;
    if (remain != 1 && remain != 5) return 0;
    ll i = 5;
    while (i * i <= n)
    {
        if (!min(n % i, n % (i + 2))) return 0;
        i += 6;
    }
    return 1;
}

map<ll, ll> generate_factors(ll n)
{
    map<ll, ll> factors;
    ll f = 2;
    while (f * f <= n)
    {
        while (n % f == 0)
        {
            factors[f]++;
            n /= f;
        }
        f++;
    }
    if (n > 1) factors[n]++;
    return factors;
}

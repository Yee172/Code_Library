#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define MAXN 1000500
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, n) for (ll i = a; i <= n; i++)
#define per(i, a, n) for (ll i = n; i >= a; i--)
ll T;
ll n;
vector<ll> prime;
ll v[MAXN + 1];

namespace Vince
{
    void init()
    {
        rep(i, 2, MAXN)
        {
            if (!v[i])
            {
                prime.pb(i);
                for (int j = 2 * i; j <= MAXN; j += i) v[j] = 1;
            }
        }
    }

    map<ll, ll> generate_factors(ll n)
    {
        map<ll, ll> factors;
        ll i = 0;
        ll f = prime[i];
        while (f * f <= n)
        {
            while (n % f == 0)
            {
                factors[f]++;
                n /= f;
            }
            f = prime[++i];
        }
        if (n > 1) factors[n]++;
        return factors;
    }

    ll solve(ll T)
    {
        cin >> n;
        map<ll, ll> fa = generate_factors(n);
        ll r = 1;
        for (map<ll, ll>::iterator it = fa.begin(); it != fa.end(); it++) r *= it->second + 1;
        return r - 1;
    }
}

using namespace Vince;
int main()
{
    FAST;
    cin >> T;
    init();
    rep(_, 1, T) cout << "Case " << _ << ": " << solve(T) << endl;
    return 0;
}

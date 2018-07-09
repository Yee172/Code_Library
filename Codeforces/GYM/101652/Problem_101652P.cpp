#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000500
typedef long long ll;
ll T;
ll l, r;
ll s[MAXN];
ll i, j;
vector<ll> p;
pair<ll, ll> num[MAXN];

int main()
{
    for (i = 2; i < MAXN; i++)
    {
        if (!s[i])
        {
            for (j = 2 * i; j < MAXN; j += i)
            {
                s[j] = 1;
            }
            p.push_back(i);
        }
    }
    cin >> l >> r;
    for (i = 0; i <= r - l; i++)
    {
        num[i].first = i + l;
        num[i].second = 1;
    }
    for (vector<ll>::iterator it = p.begin(); it != p.end(); it++)
    {
        for (i = (ll) ceil(1.0 * l / (*it)) * (*it); i <= r; i += *it)
        {
            ll sum = 1, mul = 1;
            while (num[i - l].first % *it == 0)
            {
                mul *= *it;
                sum += mul;
                num[i - l].first /= *it;
            }
            num[i-l].second *= sum;
        }
    }
    ll res = 0;
    for (i = 0; i <= r - l; i++)
    {
        if (num[i].first > 1)
        {
            num[i].second *= num[i].first + 1;
        }
        res += num[i].second;
    }
    cout << res << endl;
    return 0;
}

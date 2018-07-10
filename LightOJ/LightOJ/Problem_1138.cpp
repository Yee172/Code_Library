#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, _;
ll n;
ll i;

ll tail_zeros(ll n)
{
    ll res = 0;
    ll mul = 5;
    while (mul <= n) res += n / mul, mul *= 5;
    return res;
}

ll binary_search(ll n)
{
    ll left = 0, right = 1e18;
    while (left < right)
    {
        ll mid = (left + right) >> 1;
        ll zeros = tail_zeros(mid);
        if (zeros < n) left = mid + 1;
        else right = mid;
    }
    if (tail_zeros(left) == n) return left;
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        scanf("%lld", &n);
        printf("Case %lld: ", _);
        ll res = binary_search(n);
        if (res == -1) puts("impossible");
        else printf("%lld\n", res);
    }
    return 0;
}

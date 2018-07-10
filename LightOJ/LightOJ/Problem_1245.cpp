#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, _;
ll n;
ll i;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        printf("Case %lld: ", _);
        scanf("%lld", &n);
        ll res = 0;
        for (i = 1; i * i <= n; i++)
        {
            res += n / i;
            if (n / i != i)
                res += (n / i - n / (i + 1)) * i;
        }
        printf("%lld\n", res);
    }
    return 0;
}

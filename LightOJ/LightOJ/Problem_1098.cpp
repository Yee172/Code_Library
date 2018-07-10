#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x, y) (((x) - (y) + 1) * ((x) + (y)) / 2)
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
            res += n / i * i;
            if (n / i != i)
                res += i * su(n / i, n / (i + 1) + 1);
        }
        res -= n + (1 + n) * n / 2 - 1;
        printf("%lld\n", res - (n == 0));
    }
    return 0;
}

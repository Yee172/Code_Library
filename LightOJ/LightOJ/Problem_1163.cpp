#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll t, _;
ll n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        scanf("%lld", &n);
        printf("Case %llu: ", _);
        ll ab = 10 * n;
        if (ab % 9 == 0) printf("%llu ", ab / 9 - 1);
        printf("%llu\n", ab / 9);
    }
    return 0;
}

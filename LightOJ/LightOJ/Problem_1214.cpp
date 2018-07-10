#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
typedef long long ll;
ll t, _;
ll b;
ll i;
char s[MAXN];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    for (_ = 1; _ <= t; _++)
    {
        printf("Case %lld: ", _);
        scanf("%s%lld", s, &b);
        ll res = 0;
        for (i = s[0] == '-' ? 1 : 0; i < strlen(s); i++) res = (res * 10 + s[i] - '0') % b;
        if (res) puts("not divisible");
        else puts("divisible");
    }
    return 0;
}

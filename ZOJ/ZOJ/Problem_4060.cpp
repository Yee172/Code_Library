#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

const int MAXN = 1000050;
char s[2][MAXN];

int main()
{
    int t, n, cnt;
    ll res;
    bool dif;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%s%s", &n, s[0], s[1]);
        dif = false;
        cnt = 0;
        res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[0][i] != s[1][i])
            {
                if (!dif) dif = true, ++cnt;
            }
            else dif = false;
            if (cnt > 2) break;
        }
        if (cnt > 2) res = 0;
        else if (cnt == 2) res = 6;
        else if (cnt == 1) res = n - 1 << 1;
        else if (cnt == 0) res = (ll) n * (n + 1) >> 1;
        printf("%lld\n", res);
    }
    return 0;
}

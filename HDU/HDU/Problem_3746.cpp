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

namespace KMP
{
    const int MAXN = 100050;
    char a[MAXN];
    int len;
    int nt[MAXN];

    inline void get_next()
    {
        nt[0] = 0;
        for (int q = 1, k = 0; q < len; ++q)
        {
            while (k > 0 && a[q] != a[k]) k = nt[k - 1];
            if (a[q] == a[k]) ++k;
            nt[q] = k;
        }
    }
}
using namespace KMP;

int main()
{
    int t, circle_len;
    for (scanf("%d", &t); t--; )
    {
        scanf("%s", a);
        len = (int) strlen(a);
        get_next();
        circle_len = len - nt[len - 1];
        printf("%d\n", circle_len == len || len % circle_len ? len / circle_len * circle_len + circle_len - len : 0);
    }
    return 0;
}

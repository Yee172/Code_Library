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
    const int MAXN = 1000050;
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
    int circle_len, times, j, cas = 0;
    while (~scanf("%d", &len) && len)
    {
        printf("Test case #%d\n", ++cas);
        scanf("%s", a);
        get_next();
        for (int i = 1; i < len; ++i)
        {
            j = i + 1;
            circle_len = j - nt[i];
            if (j % circle_len == 0)
            {
                times = j / circle_len;
                if (times > 1) printf("%d %d\n", j, times);
            }
        }
        puts("");
    }
    return 0;
}

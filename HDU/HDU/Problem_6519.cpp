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

char s[105];

int main()
{
    int n, m, k;
    while (~scanf("%d %d %d", &n, &m, &k))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            for (int t = 0; t < k; ++t)
            {
                for (int j = 0; j < m; ++j)
                    for (int l = 0; l < k; ++l)
                        putchar(s[j]);
                putchar('\n');
            }
        }
    }
    return 0;
}

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
    const int MAXN = 1050;
    const int MAXM = 1050;
    char a[MAXN];
    int len_a;
    int nt[MAXN];
    char b[MAXM];
    int len_b;

    inline void get_next()
    {
        nt[0] = 0;
        for (int q = 1, k = 0; q < len_b; ++q)
        {
            while (k > 0 && b[q] != b[k]) k = nt[k - 1];
            if (b[q] == b[k]) ++k;
            nt[q] = k;
        }
    }

    inline int kmp() // return index starts from 0, -1 means none
    {
        int res = 0;
        for (int i = 0, k = 0; i < len_a; ++i)
        {
            while (k > 0 && b[k] != a[i]) k = nt[k - 1];
            if (b[k] == a[i]) ++k;
            if (k == len_b)
            {
                k = 0;
                ++res;
            }
        }
        return res;
    }
}
using namespace KMP;

int main()
{
    while (~scanf("%s", a) && a[0] != '#')
    {
        scanf("%s", b);
        len_a = (int) strlen(a);
        len_b = (int) strlen(b);
        get_next();
        printf("%d\n", kmp());
    }
    return 0;
}

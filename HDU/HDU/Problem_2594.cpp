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
    const int MAXN = 50050;
    const int MAXM = 50050;
    char a[MAXN];
    int len_a;
    char b[MAXM];
    int len_b;
    int _next[MAXM];

    inline void get_next()
    {
        _next[0] = 0;
        for (int q = 1, k = 0; q < len_b; ++q)
        {
            while (k > 0 && b[q] != b[k]) k = _next[k - 1];
            if (b[q] == b[k]) ++k;
            _next[q] = k;
        }
    }

    inline int kmp()
    {
        int k = 0;
        for (int i = 0; i < len_a; ++i)
        {
            while (k > 0 && b[k] != a[i]) k = _next[k - 1];
            if (b[k] == a[i]) ++k;
            if (k == len_b && i != len_a - 1) k = _next[k - 1];
        }
        return k;
    }
}
using namespace KMP;

int main()
{
    int k;
    while (~scanf("%s", b) && ~scanf("%s", a))
    {
        len_a = (int) strlen(a);
        len_b = (int) strlen(b);
        get_next();
        k = kmp();
        if (k) b[k] = '\0', printf("%s %d\n", b, k);
        else puts("0");
    }
    return 0;
}

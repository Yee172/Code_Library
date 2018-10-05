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
    const int MAXM = 10050;
    int a[MAXN];
    int len_a;
    int nt[MAXN];
    int b[MAXM];
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
        for (int i = 0, k = 0; i < len_a; ++i)
        {
            while (k > 0 && b[k] != a[i]) k = nt[k - 1];
            if (b[k] == a[i]) ++k;
            if (k == len_b) return i - len_b + 1;
        }
        return -1;
    }
}
using namespace KMP;

int main()
{
    int t, res;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &len_a, &len_b);
        rep(i, len_a) scanf("%d", a + i);
        rep(i, len_b) scanf("%d", b + i);
        get_next();
        res = kmp();
        res = res == -1 ? -1 : res + 1;
        printf("%d\n", res);
    }
    return 0;
}

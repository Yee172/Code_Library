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
    const int MAXM = 100050;
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
        for (int i = len_a + 1 >> 1; i < len_a; ++i)
        {
            while (k > 0 && b[k] != a[i]) k = _next[k - 1];
            if (b[k] == a[i]) ++k;
        }
        return k;
    }
}
using namespace KMP;
char cipher[50];
char reverse_cipher[50];

int main()
{
    int t, k;
    for (scanf("%d", &t); t--; )
    {
        scanf("%s%s", cipher, a);
        rep(i, 26) reverse_cipher[cipher[i] - 'a'] = (char) ('a' + i);
        len_a = len_b = (int) strlen(a);
        rep(i, len_a) b[i] = reverse_cipher[a[i] - 'a'];
        get_next();
        k = len_a - kmp();
        rep(i, k) putchar(a[i]);
        rep(i, k) putchar(reverse_cipher[a[i] - 'a']);
        puts("");
    }
    return 0;
}

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

int n;
const int inf = 0x3f3f3f3f;
inline void get_max(int &a, const int &b) { a = a > b ? a : b; }
inline void get_min(int &a, const int &b) { a = a < b ? a : b; }

namespace KMP
{
    const int MAXN = 205;
    const int MAXM = 4005;
    char a[MAXM][MAXN];
    int len[MAXM];
    int _next[MAXN][MAXN];

    inline void get_next()
    {
        rep(i, len[0])
        {
            _next[i][i] = i;
            for (int q = i + 1, k = i; q < len[0]; ++q)
            {
                while (k > i && a[0][q] != a[0][k]) k = _next[i][k - 1];
                if (a[0][q] == a[0][k]) ++k;
                _next[i][q] = k;
            }
        }
    }

    inline void kmp()
    {
        int max_len = 0, start = -1, tmp, mx;
        bool change;
        rep(_, len[0])
        {
            if (len[0] - _ < max_len) break;
            tmp = inf;
            for (int j = 1; j < n; ++j)
            {
                mx = 0;
                for (int i = 0, k = _; i < len[j]; ++i)
                {
                    while (k > _ && a[0][k] != a[j][i]) k = _next[_][k - 1];
                    if (a[0][k] == a[j][i]) ++k;
                    get_max(mx, k - _);
                    if (k == len[0]) break;
                }
                get_min(tmp, mx);
                if (tmp < max_len) break;
            }
            if (tmp > max_len) max_len = tmp, start = _;
            if (tmp == max_len)
            {
                change = false;
                for (int p = start, q = _, c = 0; c < max_len; ++c, ++p, ++q)
                {
                    if (a[0][p] < a[0][q]) break;
                    if (a[0][p] > a[0][q])
                    {
                        change = true;
                        break;
                    }
                }
                if (change) start = _;
            }
        }
        if (start == -1 || max_len == inf) puts("IDENTITY LOST");
        else
        {
            for (int p = start, c = 0; c < max_len; ++c, ++p) putchar(a[0][p]);
            puts("");
        }
    }
}
using namespace KMP;

int main()
{
    while (~scanf("%d", &n) && n)
    {
        rep(i, n) scanf("%s", a[i]), len[i] = (int) strlen(a[i]);
        get_next();
        kmp();
    }
    return 0;
}

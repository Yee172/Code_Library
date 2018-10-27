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
    char s[MAXN];
    int len;
    int _next[MAXN];

    inline void get_next()
    {
        _next[0] = 0;
        for (int q = 1, k = 0; q < len; ++q)
        {
            while (k > 0 && s[q] != s[k]) k = _next[k - 1];
            if (s[q] == s[k]) ++k;
            _next[q] = k;
        }
    }
}
using namespace KMP;

namespace maximum_minimum_string
{
    //const int MAXN = 1000050;
    //char s[MAXN];
    //int len;

    inline int __mod__(const int a) { return a < len ? a : a - a / len * len; }

    inline int get_start_index_of_minimum_string()
    {
        int i = 0, j = 1, k = 0, delta;
        while (k < len && i < len && j < len)
        {
            delta = s[__mod__(i + k)] - s[__mod__(j + k)];
            if (delta == 0) ++k;
            else
            {
                if (delta > 0) i += k + 1, i += (i == j);
                else j += k + 1, j += (i == j);
                k = 0;
            }
        }
        return i < j ? i : j;
    }

    inline int get_start_index_of_maximum_string()
    {
        int i = 0, j = 1, k = 0, delta;
        while (k < len && i < len && j < len)
        {
            delta = s[__mod__(i + k)] - s[__mod__(j + k)];
            if (delta == 0) ++k;
            else
            {
                if (delta < 0) i += k + 1, i += (i == j);
                else j += k + 1, j += (i == j);
                k = 0;
            }
        }
        return i < j ? i : j;
    }
}
using namespace maximum_minimum_string;

int main()
{
    int circle_len, res;
    while (~scanf("%s", s))
    {
        len = (int) strlen(s);
        KMP::get_next();
        circle_len = len - _next[len - 1];
        res = len % circle_len ? 1 : len / circle_len;
        printf("%d %d %d %d\n", get_start_index_of_minimum_string() + 1, res, get_start_index_of_maximum_string() + 1, res);
    }
    return 0;
}

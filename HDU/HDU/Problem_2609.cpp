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

namespace maximum_minimum_string
{
    const int MAXN = 105;
    char s[MAXN];
    int len;

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
}
using namespace maximum_minimum_string;

unordered_set<string> p;

int main()
{
    int n, index;
    while (~scanf("%d", &n))
    {
        p.clear();
        rep(i, n)
        {
            scanf("%s", s);
            if (i == 0) len = (int) strlen(s);
            index = get_start_index_of_minimum_string();
            p.insert(string(s + index, s + len) + string(s, s + index));
        }
        printf("%d\n", (int) p.size());
    }
    return 0;
}

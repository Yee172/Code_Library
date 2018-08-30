#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <time.h>
#include <vector>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <complex>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
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

int n, bit[1050][1050];

inline int bit_sum(const int x, const int y)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            res += bit[i][j];
    return res;
}

inline void bit_add(const int x, const int y, const int value)
{
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= n; j += j & -j)
            bit[i][j] += value;
}

inline void bit_range_add(const int x1, const int y1, const int x2, const int y2, const int value)
{
    bit_add(x1, y1, value);
    bit_add(x1, y2 + 1, -value);
    bit_add(x2 + 1, y1, -value);
    bit_add(x2 + 1, y2 + 1, value);
}

int main()
{
    int t, q, x, y, z, w;
    char c[2];
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &n, &q);
        memset(bit, 0, sizeof bit);
        rep(_, q)
        {
            scanf("%s", c);
            if (c[0] == 'C') scanf("%d%d%d%d", &x, &y, &z, &w), bit_range_add(x, y, z, w, 1);
            else scanf("%d%d", &x, &y), printf("%d\n", bit_sum(x, y) & 1);
        }
        puts("");
    }
    return 0;
}

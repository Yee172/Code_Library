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

namespace KMP
{
    const int MAXN = 400050;
    char a[MAXN];
    int len;
    int _next[MAXN];

    inline void get_next()
    {
        _next[0] = 0;
        for (int q = 1, k = 0; q < len; ++q)
        {
            while (k > 0 && a[q] != a[k]) k = _next[k - 1];
            if (a[q] == a[k]) ++k;
            _next[q] = k;
        }
    }
}
using namespace KMP;
int res[MAXN];
int cnt;

int main()
{
    while (~scanf("%s", a))
    {
        len = (int) strlen(a);
        get_next();
        for (res[0] = len, cnt = 0; res[cnt]; ++cnt)
            res[cnt + 1] = _next[res[cnt] - 1];
        for (int i = cnt - 1; i >= 0; --i) printf("%d%c", res[i], i ? ' ' : '\n');
    }
    return 0;
}

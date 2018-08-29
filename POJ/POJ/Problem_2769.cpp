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

inline int __mod__(const long long a, const int b) { return (int) (a < b ? a : a - a / b * b); }

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

int a[500];
int vis[1000000];

int main()
{
    int t, n, tmp;
    bool ok;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d", &n);
        rep(i, n) scanf("%d", a + i);
        for (int i = 1; ; ++i)
        {
            ok = true;
            rep(j, i) vis[j] = false;
            rep(j, n)
            {
                tmp = __mod__(a[j], i);
                if (vis[tmp])
                {
                    ok = false;
                    break;
                }
                vis[tmp] = true;
            }
            if (ok)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}

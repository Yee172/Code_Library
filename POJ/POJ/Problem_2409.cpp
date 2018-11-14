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

inline int __pow__(int x, int n)
{
    int r = 1;
    for (; n; n >>= 1, x *= x) if (n & 1) r *= x;
    return r;
}

int main()
{
    int s, c;
    int res;
    while (~scanf("%d%d", &c, &s) && (s || c))
    {
        res = 0;
        rep(i, s) res += __pow__(c, __gcd(i, s));
        if (s & 1) res += __pow__(c, s + 1 >> 1) * s;
        else res += (__pow__(c, s >> 1) + __pow__(c, s + 2 >> 1)) * (s >> 1);
        (res /= s) >>= 1;
        printf("%d\n", res);
    }
    return 0;
}

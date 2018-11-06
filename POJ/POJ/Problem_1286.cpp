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

inline ll __pow__(ll x, ll n)
{
    ll r = 1;
    for (; n; n >>= 1, x *= x) if (n & 1) r *= x;
    return r;
}

int main()
{
    int n;
    ll res;
    while (~scanf("%d", &n) && n != -1)
    {
        if (n == 0)
        {
            puts("0");
            continue;
        }
        res = 0;
        _rep(i, n) res += __pow__(3, __gcd(i, n));
        if (n & 1) res += n * __pow__(3, n + 1 >> 1);
        else res += n / 2 * (__pow__(3, n >> 1) + __pow__(3, n + 2 >> 1));
        res /= 2 * n;
        printf("%lld\n", res);
    }
    return 0;
}

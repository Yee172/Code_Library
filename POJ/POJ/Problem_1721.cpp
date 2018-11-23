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

int n, s, f, cnt;
int a[3][1005];

inline void get_next()
{
    for (int i = 1; i <= n; ++i) a[f ^ 1][i] = a[f][a[f][i]];
    f ^= 1;
}

inline bool not_same()
{
    for (int i = 1; i <= n; ++i) if (a[2][i] != a[f][i]) return true;
    return false;
}

int main()
{
    scanf("%d%d", &n, &s);
    _rep(i, n) scanf("%d", a[0] + i), a[2][i] = a[0][i];
    for (get_next(), cnt = 1; not_same(); ++cnt, get_next());
    for (cnt = ((cnt - s) % cnt + cnt) % cnt; cnt; --cnt) get_next();
    _rep(i, n) printf("%d\n", a[f][i]);
    return 0;
}

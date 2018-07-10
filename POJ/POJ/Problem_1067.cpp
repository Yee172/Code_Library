#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define square(x) ((x) * (x))

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

const double phi = (sqrt(5) + 1) / 2;
const double phi2 = square(phi);
ll a, b;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~ scanf("%lld%lld", &a, &b))
    {
        if (a > b) a ^= b, b ^= a, a ^= b;
        ll d = b - a;
        if (a == (ll) (phi * d) && b == (ll) (phi2 * d)) puts("0");
        else puts("1");
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

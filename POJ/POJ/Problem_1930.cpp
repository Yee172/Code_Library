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

const ll inf = 0x3f3f3f3f3f3f3f3f;
ll power(ll a,ll b) {ll r = 1; for(; b; b >>= 1) {if (b & 1) r = r * a; a = a * a;} return r;}
char s[10000], ss[10000];
ll a;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while(1)
    {
        fgets(s, 1500, stdin);
        if (s[1] != '.') break;
        sscanf(s, "0.%s", ss);
        for(int i = 1; i < 1500; i++) if (ss[i] == '.') {ss[i] = '\0'; break;}
        sscanf(ss, "%lld", &a);
        ll len = strlen(ss);
        ll p = inf, q = inf;
        ll up, under;
        for (ll i = 1, tmp = 10, tmpp = 9, tmppp = power(10, len - 1); i <= len; i++, tmp *= 10, tmpp = tmp - 1, tmppp /= 10)
        {
            ll cycle = a % tmp;
            ll head = a / tmp;
            up = cycle + tmpp * head;
            under = tmppp * tmpp;
            ll g = __gcd(up, under);
            up /= g;
            under /= g;
            if (under < q) p = up, q = under;
        }
        printf("%lld/%lld\n", p, q);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

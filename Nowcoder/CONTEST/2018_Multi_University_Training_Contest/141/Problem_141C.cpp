#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define square(x) ((x) * (x))
inline int sign(const int x) { return x < 0 ? -1 : x > 0; }

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

#include<ext/rope>
using namespace __gnu_cxx;
rope<int> card;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    time_t __START__ = clock();
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    card.clear();
    _rep(i, n) card.push_back(i);
    int start, length;
    rep(i, m)
    {
        scanf("%d%d", &start, &length);
        card = card.substr(start - 1, length)
               + card.substr(0, start - 1)
               + card.substr(start + length - 1, n - start - length + 1);
    }
    rep(i, n) printf("%d%c", card[i], " \n"[i == n - 1]);
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

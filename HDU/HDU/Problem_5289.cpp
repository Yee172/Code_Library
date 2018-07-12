#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)
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

#define MAXN 100050
#define MAXLOGN 20

template <typename T>
class RMQ
{
public:
    RMQ() {}

    inline T *operator[](int i) {return maximum[i];}

    inline void init(T a[], int len, int start=1)
    {
        for (int i = 1, k = start; i <= len; i++, k++)
            minimum[i][0] = maximum[i][0] = a[k];
        for (int j = 1, k = 2; k <= len; j++, k <<= 1)
            for (int i = 1; i + k - 1 <= len; i++)
            {
                maximum[i][j] = max(maximum[i][j - 1], maximum[i + (k >> 1)][j - 1]);
                minimum[i][j] = min(minimum[i][j - 1], minimum[i + (k >> 1)][j - 1]);
            }
    }

    inline T query(int left, int right)
    {
        int k = 0;
        for (; 1 << k + 1 <= right - left + 1; k++);
        return max(maximum[left][k], maximum[right - (1 << k) + 1][k]) -
               min(minimum[left][k], minimum[right - (1 << k) + 1][k]);
    }
private:
    T maximum[MAXN][MAXLOGN];
    T minimum[MAXN][MAXLOGN];
};

RMQ<int> rmq;
int T, n, k, a[MAXN];

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d%d", &n, &k);
        _rep(i, n) scanf("%d", a + i);
        rmq.init(a, n);
        ll res = 0;
        _rep(i, n)
        {
            int l = i, r = n;
            while (l < r)
            {
                int m = l + r + 1 >> 1;
                if (rmq.query(i, m) < k) l = m;
                else r = m - 1;
            }
            res += l - i + 1;
        }
        printf("%lld\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

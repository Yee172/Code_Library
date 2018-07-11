#include <bits/stdc++.h>
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

#define MAXN 200050
ll a[MAXN];

template <typename T>
class SegmentTree
{
public:
    int n;
    int bit;
    SegmentTree() {}
    SegmentTree(int n) : n(n) {bit = 0;}

    void build(const T a[], const int start=1)
    {
        bit = 1;
        while (bit <= n + 1) bit <<= 1;
        for (int i = bit + 1, k = start; i <= bit + n; i++, k++)
            tree[i].maximum = a[k];
        for (int i = bit - 1; i > 0; i--)
            tree[i].maximum = max(tree[i << 1].maximum, tree[i << 1 | 1].maximum);
    }

    void update(int i, T val)
    {
        i += bit;
        tree[i].maximum = val;
        for (i >>= 1; i; i >>= 1)
            tree[i].maximum = max(tree[i << 1].maximum, tree[i << 1 | 1].maximum);
    }

    inline T query_maximum(int left, int right)
    {
        T lans = 0;
        T rans = 0;
        left += bit - 1;
        right += bit + 1;
        while (left ^ right ^ 1)
        {
            if (~ left & 1) lans = max(lans, tree[left ^ 1].maximum);
            if (right & 1) rans = max(rans, tree[right ^ 1].maximum);
            left >>= 1;
            right >>= 1;
        }
        return max(lans, rans);
    }

private:
    struct node
    {
        T maximum;
    }tree[MAXN << 2];
};

int n, m;
char C;
ll A, B;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    while (~ scanf("%d%d", &n, &m))
    {
        _rep(i, n) scanf("%lld", a + i);
        SegmentTree<ll> tree = SegmentTree<ll>(n);
        tree.build(a);
        rep(i, m)
        {
            scanf("%s %lld%lld", &C, &A, &B);
            if (C == 'Q') printf("%lld\n", tree.query_maximum(A, B));
            if (C == 'U') tree.update(A, B);
        }
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

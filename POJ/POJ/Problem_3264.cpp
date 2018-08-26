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

#define MAXN 50050
const ll INF = 0x3f3f3f3f3f3f3f3f;
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
            tree[i].minimum = tree[i].maximum = a[k];
        for (int i = bit - 1; i > 0; i--)
        {
            tree[i].maximum = max(tree[i << 1].maximum, tree[i << 1 | 1].maximum);
            tree[i].minimum = min(tree[i << 1].minimum, tree[i << 1 | 1].minimum);
            tree[i << 1].maximum -= tree[i].maximum;
            tree[i << 1].minimum -= tree[i].minimum;
            tree[i << 1 | 1].maximum -= tree[i].maximum;
            tree[i << 1 | 1].minimum -= tree[i].minimum;
        }
    }

    inline T query_maximum(int left, int right)
    {
        T lans = 0;
        T rans = 0;
        if (left == right)
        {
            left += bit;
            while (left) lans += tree[left].maximum, left >>= 1;
            return lans;
        }
        left += bit;
        right += bit;
        while (left ^ right ^ 1)
        {
            lans += tree[left].maximum;
            rans += tree[right].maximum;
            if (~ left & 1) lans = max(lans, tree[left ^ 1].maximum);
            if (right & 1) rans = max(rans, tree[right ^ 1].maximum);
            left >>= 1;
            right >>= 1;
        }
        lans += tree[left].maximum;
        rans += tree[right].maximum;
        T ans = max(lans, rans);
        while (left > 1) left >>= 1, ans += tree[left].maximum;
        return ans;
    }

    inline T query_minimum(int left, int right)
    {
        T lans = 0;
        T rans = 0;
        if (left == right)
        {
            left += bit;
            while (left) lans += tree[left].minimum, left >>= 1;
            return lans;
        }
        left += bit;
        right += bit;
        while (left ^ right ^ 1)
        {
            lans += tree[left].minimum;
            rans += tree[right].minimum;
            if (~ left & 1) lans = min(lans, tree[left ^ 1].minimum);
            if (right & 1) rans = min(rans, tree[right ^ 1].minimum);
            left >>= 1;
            right >>= 1;
        }
        lans += tree[left].minimum;
        rans += tree[right].minimum;
        T ans = min(lans, rans);
        while (left > 1) left >>= 1, ans += tree[left].minimum;
        return ans;
    }

private:
    struct node
    {
        T minimum, maximum;
    }tree[MAXN << 2];
};

int n, q;
int A, B;

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    scanf("%d%d", &n, &q);
    _rep(i, n) scanf("%lld", a + i);
    SegmentTree<ll> tree = SegmentTree<ll>(n);
    tree.build(a);
    rep(i, q)
    {
        scanf("%d%d", &A, &B);
        printf("%lld\n", tree.query_maximum(A, B) - tree.query_minimum(A, B));
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

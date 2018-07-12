#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
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

#define MAXN 30050
const int inf = 0x3f3f3f3f;

template <typename T>
class SegmentTree
{
public:
    SegmentTree(int n) : n(n) {for (bit = 1; bit < n + 1; bit <<= 1);}
    inline void build(const T * a, const int start=1)
    {
        for (int i = bit + 1, k = start; i <= bit + n; i++, k++)
            sum[i] = maximum[i] = a[k];
        for (int i = bit - 1; i; i--)
        {
            sum[i] = sum[i << 1] + sum[i << 1 | 1];
            maximum[i] = max(maximum[i << 1], maximum[i << 1 | 1]);
        }
    }
    inline void update(const int index, const T val)
    {
        int i = index + bit;
        sum[i] = maximum[i] = val;
        for (i >>= 1; i; i >>= 1)
        {
            sum[i] = sum[i << 1] + sum[i << 1 | 1];
            maximum[i] = max(maximum[i << 1], maximum[i << 1 | 1]);
        }
    }
    inline T query_sum(const int left, const int right)
    {
        int l = left + bit - 1;
        int r = right + bit + 1;
        T lans = 0;
        T rans = 0;
        for (; l ^ r ^ 1; l >>= 1, r >>= 1)
        {
            if (~ l & 1) lans += sum[l ^ 1];
            if (r & 1) rans += sum[r ^ 1];
        }
        return lans + rans;
    }
    inline T query_maximum(const int left, const int right)
    {
        int l = left + bit - 1;
        int r = right + bit + 1;
        T lans = -inf;
        T rans = -inf;
        for (; l ^ r ^ 1; l >>= 1, r >>= 1)
        {
            if (~ l & 1) lans = max(lans, maximum[l ^ 1]);
            if (r & 1) rans = max(rans, maximum[r ^ 1]);
        }
        return max(lans, rans);
    }
private:
    int n;
    int bit;
    T sum[MAXN << 2];
    T maximum[MAXN << 2];
};

class CutTree
{
public:
    int son[MAXN], father[MAXN];
    int depth[MAXN], son_size[MAXN];
    int father_top[MAXN], id[MAXN], tot;
    CutTree() {}
    void init()
    {
        dfs1(1, 1, 0);
        dfs2(1, 1);
    }
    inline void insert_edge(int u, int v)
    {
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
private:
    vector<int> edge[MAXN];
    void dfs1(int x, int v, int dpt)
    {
        father[x] = v;
        son_size[x] = 1;
        depth[x] = dpt;
        int sz = edge[x].size();
        int mxsz = 0;
        int mxn = 0;
        for(int i = 0; i < sz; i++)
        {
            int u = edge[x][i];
            if (u==v) continue;
            dfs1(u, x, dpt + 1);
            son_size[x] += son_size[u];
            if(son_size[u] > mxsz)
            {
                mxsz = son_size[u];
                mxn = u;
            }
        }
        son[x] = mxn;
    }
    void dfs2(int x, int ftp)
    {
        father_top[x] = ftp;
        id[x] = ++tot;
        if (son[x]) dfs2(son[x],ftp);
        int sz = edge[x].size();
        for(int i = 0; i < sz; i++)
        {
            int u = edge[x][i];
            if(u == father[x] || u == son[x]) continue;
            dfs2(u, u);
        }
    }
};

int n, a, b, q, u, v, value[MAXN], A[MAXN];
char c[10];

inline void gao1(CutTree &t, SegmentTree<int> &s, const int i, const int val)
{
    s.update(t.id[i], val);
}

inline void gao2(CutTree &t, SegmentTree<int> &s, int x, int y)
{
    int ans = 0;
    while(t.father_top[x] != t.father_top[y])
    {
        if(t.depth[t.father_top[x]] < t.depth[t.father_top[y]])
        {
            ans += s.query_sum(t.id[t.father_top[y]], t.id[y]);
            y = t.father[t.father_top[y]];
        }
        else
        {
            ans += s.query_sum(t.id[t.father_top[x]], t.id[x]);
            x = t.father[t.father_top[x]];
        }
    }
    if(t.depth[x] > t.depth[y]) x ^= y, y ^= x, x ^= y;
    printf("%d\n", ans + s.query_sum(t.id[x], t.id[y]));
}

inline void gao3(CutTree &t, SegmentTree<int> &s, int x, int y)
{
    int ans = -inf;
    while(t.father_top[x] != t.father_top[y])
    {
        if(t.depth[t.father_top[x]] < t.depth[t.father_top[y]])
        {
            ans = max(ans, s.query_maximum(t.id[t.father_top[y]], t.id[y]));
            y = t.father[t.father_top[y]];
        }
        else
        {
            ans = max(ans, s.query_maximum(t.id[t.father_top[x]], t.id[x]));
            x = t.father[t.father_top[x]];
        }
    }
    if(t.depth[x] > t.depth[y]) x ^= y, y ^= x, x ^= y;
    printf("%d\n", max(ans, s.query_maximum(t.id[x], t.id[y])));
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    scanf("%d", &n);
    SegmentTree<int> tree(n);
    CutTree cut_tree;
    _rep(i, n - 1) scanf("%d%d", &a, &b), cut_tree.insert_edge(a, b);
    _rep(i, n) scanf("%d", value + i);
    cut_tree.init();
    _rep(i, n) A[cut_tree.id[i]] = value[i];
    tree.build(A);
    scanf("%d", &q);
    rep(i, q)
    {
        scanf("%s%d%d", c, &u, &v);
        if (c[0] == 'C') gao1(cut_tree, tree, u, v);
        if (c[1] == 'S') gao2(cut_tree, tree, u, v);
        if (c[1] == 'M') gao3(cut_tree, tree, u, v);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

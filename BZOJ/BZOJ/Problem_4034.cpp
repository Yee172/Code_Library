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

#define MAXN 100050

template <typename T>
class SegmentTree
{
public:
    SegmentTree(int n) : n(n) {for (bit = 1; bit < n + 1; bit <<= 1);}

    void build(const T * a, const int start=1)
    {
        for (int i = bit + 1, k = start; i <= bit + n; i++, k++)
            sum[i] = a[k];
        for (int i = bit - 1; i; i--)
        {
            sum[i] = sum[i << 1] + sum[i << 1 | 1];
        }
        for (int i = 1; i <= bit + n; i++) add[i] = 0;
    }

    inline void update(const int left, const int right, T val)
    {
        T lans = 0;
        T rans = 0;
        T k = 1;
        int l = left + bit - 1;
        int r = right + bit + 1;
        for (; l ^ r ^ 1; l >>= 1, r >>= 1, k <<= 1)
        {
            sum[l] += val * lans;
            sum[r] += val * rans;
            if (~ l & 1)
                sum[l ^ 1] += val * k, add[l ^ 1] += val, lans += k;
            if (r & 1)
                sum[r ^ 1] += val * k, add[r ^ 1] += val, rans += k;
        }
        for (; l; l >>= 1, r >>= 1)
        {
            sum[l] += val * lans;
            sum[r] += val * rans;
        }
    }

    inline T query(const int left, const int right)
    {
        T lans = 0;
        T rans = 0;
        T k = 1;
        T ans = 0;
        int l = left + bit - 1;
        int r = right + bit + 1;
        for (; l ^ r ^ 1; l >>= 1, r >>= 1, k <<= 1)
        {
            if (add[l]) ans += add[l] * lans;
            if (add[r]) ans += add[r] * rans;
            if (~ l & 1)
                ans += sum[l ^ 1], lans += k;
            if (r & 1)
                ans += sum[r ^ 1], rans += k;
        }
        for (; l; l >>= 1, r >>= 1)
        {
            ans += add[l] * lans;
            ans += add[r] * rans;
        }
        return ans;
    }
private:
    int n;
    int bit;
    T sum[MAXN << 2];
    T add[MAXN << 2];
};

class CutTree
{
public:
    int son[MAXN], father[MAXN], gunna[MAXN];
    int depth[MAXN], son_size[MAXN];
    int father_top[MAXN], id[MAXN], tot;
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
        gunna[x] = tot;
    }
} cut_tree;

int n, m, u, v, a, b, c;
ll value[MAXN];
ll A[MAXN];

inline void gao(CutTree &t, SegmentTree<ll> &s, int x, int y)
{
    ll ans = 0;
    while(t.father_top[x] != t.father_top[y])
    {
        if(t.depth[t.father_top[x]] < t.depth[t.father_top[y]])
        {
            ans += s.query(t.id[t.father_top[y]], t.id[y]);
            y = t.father[t.father_top[y]];
        }
        else
        {
            ans += s.query(t.id[t.father_top[x]], t.id[x]);
            x = t.father[t.father_top[x]];
        }
    }
    if(t.depth[x] > t.depth[y]) x ^= y, y ^= x, x ^= y;
    printf("%lld\n", ans + s.query(t.id[x], t.id[y]));
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    time_t __START__ = clock();
#endif
    scanf("%d%d", &n, &m);
    SegmentTree<ll> tree(n);
    _rep(i, n) scanf("%lld", value + i);
    _rep(i, n - 1) scanf("%d%d", &u, &v), cut_tree.insert_edge(u, v);
    cut_tree.init();
    _rep(i, n) A[cut_tree.id[i]] = value[i];
    tree.build(A);
    rep(i, m)
    {
        scanf("%d%d", &a, &b);
        if (a == 1) scanf("%d", &c), tree.update(cut_tree.id[b], cut_tree.id[b], c);
        if (a == 2) scanf("%d", &c), tree.update(cut_tree.id[b], cut_tree.gunna[b], c);
        if (a == 3) gao(cut_tree, tree, 1, b);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

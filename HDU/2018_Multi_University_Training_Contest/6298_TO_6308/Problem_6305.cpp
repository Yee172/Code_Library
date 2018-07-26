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

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

const int MAXN = 1000050;
const ll MOD = 0x3b9aca07;
ll mod_inverse[MAXN];
inline void init_mod_inverse()
{
    mod_inverse[0] = 0, mod_inverse[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        mod_inverse[i] = (MOD - MOD / i) * mod_inverse[MOD % i] % MOD;
}

template <typename T_key, typename T_value>
class CartesianTree
{
public:
    struct node
    {
        T_key key;
        T_value value;
        int index;
        bool operator < (const node &b) { return key < b.key; }
    };
    vector<int> left_child, right_child, stack, size;
    int root;
    vector<node> member;
    explicit CartesianTree(int n) : n(n)
    {
        resize(left_child, n, -1);
        resize(right_child, n, -1);
        resize(stack, n);
        member.resize(static_cast<unsigned long>(n));
    }

    inline void initialize() { for (int i = 0; i < n; i++) left_child[i] = right_child[i] = -1; }

    node & operator [] (const int i) { return member[i]; }

    inline void build(const T_key * key, const T_value * value, const int key_start=1, const int value_start=1)
    {
        for (int i = 0, j = key_start, k = value_start; i < n; i++)
            member[i].key = key[j++], member[i].value = value[k++], member[i].index = i;
        sort(member.begin(), member.end());
        int top = 0, now = -1;
        for (int i = 0; i < n; i++)
        {
            for (now = top; now && member[stack[now - 1]].value < member[i].value; now--);
            if (now) right_child[member[stack[now - 1]].index] = member[i].index;
            if (now < top) left_child[member[i].index] = member[stack[now]].index;
            stack[now++] = i;
            top = now;
        }
        root = member[stack[0]].index;
    }

    void get_size()
    {
        resize(size, n);
        _dfs(root);
    }
protected:
    int n;

    template <typename T>
    inline void resize(vector<T> &a, const int n, const int x=0) { a.resize(static_cast<unsigned long>(n), x); }

    int _dfs(int root)
    {
        int result = 1;
        if (left_child[root] != -1) result += _dfs(left_child[root]);
        if (right_child[root] != -1) result += _dfs(right_child[root]);
        return size[root] = result;
    }
};

int a[MAXN], b[MAXN];
signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    time_t __START__ = clock();
#endif
    init_mod_inverse();
    int t, n;
    ll res;
    scanf("%d", &t);
    rep(i, MAXN) a[i] = i;
    while (t--)
    {
        scanf("%d", &n);
        res = mod_inverse[2] * n % MOD;
        CartesianTree<int, int> ct(n);
        _rep(i, n) scanf("%d", b + i);
        ct.build(a, b, 0, 1);
        ct.get_size();
        rep(i, n) (res *= mod_inverse[ct.size[i]]) %= MOD;
        printf("%lld\n", res);
    }
#ifdef Yee_172
    time_t __END__ = clock();
    fprintf(stderr, "TOTAL TIME: %.12f ms\n", (__END__ - __START__) / (double)CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}

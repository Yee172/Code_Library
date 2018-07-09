#include <bits/stdc++.h>
#define MAXN 400005
#define REP(start, end, step) for (int $i = (start); $i < (end); $i += (step))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
#define lson (now<<1)
#define rson (now<<1|1)


int f(int n)
{
    int d = 2, r = 1, c = 1, b = 1, i;
    while (d * d <= n)
    {
        while (n % d == 0)
        {
            if (d == b)
            {
                c++;
            }
            if (d > b)
            {
                r *= c;
                c = 2;
                b = d;
            }
            n /= d;
        }
        d++;
    }
    if (n > 1)
    {
        if (n == b)
        {
            c++;
        }
        if (n > b)
        {
            r *= c;
            c = 2;
        }
    }
    return r * c;
}

inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

struct Node
{
    int ma;
    ll s;
}t[MAXN<<2];

void Build(int now,int l,int r)
{
    if (l == r)
    {
        t[now].ma = t[now].s = read();
        return;
    }
    int mid = (l + r) >> 1;
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
    t[now].s = t[lson].s + t[rson].s;
    t[now].ma = max(t[lson].ma, t[rson].ma);
}

void Modify(int now,int l,int r,int L,int R)
{
    if (t[now].ma <= 2)
        return;
    if (l == r)
    {
        t[now].s = t[now].ma = f(t[now].ma);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
        Modify(lson, l, mid, L, R);
    if (R > mid)
        Modify(rson, mid + 1, r, L, R);
    t[now].s = t[lson].s + t[rson].s;
    t[now].ma = max(t[lson].ma, t[rson].ma);
}

ll Query(int now,int l,int r,int L,int R)
{
    if (L <= l && r <= R)
        return t[now].s;
    ll ret = 0;
    int mid = (l + r) >> 1;
    if (L <= mid)
        ret += Query(lson, l, mid, L, R);
    if (R > mid)
        ret += Query(rson, mid + 1, r, L, R);
    return ret;
}

int main(int argc, char const *argv[])
{
    FAST;
    int n = read(), m = read();
    Build(1, 1, n);
    while (m--)
    {
        int t = read(), l = read(), r = read();
        if (t == 1)
            Modify(1, 1, n, l, r);
        else
            printf("%I64d\n", Query(1, 1, n, l, r));
    }
    return 0;
}

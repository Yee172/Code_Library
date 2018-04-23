#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rep_(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define per_(i, a, n) for (int i = n; i >= a; i--)
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int,int> PII;
const ll mod = 1000000007;
const ll mod2inv = 500000004;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll powmod(ll a,ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}
ll inv(ll x) {if (x == 1) return 1; else return (mod - mod / x) * inv(mod % x) % mod;}
ll inv(ll x) {return powmod(x, mod - 2);}
const ll MAXN = 1000005;


int main()
{
    FAST;

    return 0;
}

int is_prime(ll n)
{
    if (n == 2 || n == 3) return 1;
    ll remain = n % 6;
    if (remain != 1 && remain != 5) return 0;
    ll i = 5;
    while (i * i <= n)
    {
        if (!min(n % i, n % (i + 2))) return 0;
        i += 6;
    }
    return 1;
}

map<ull, ull> generate_factors(ull n)
{
    map<ull, ull> factors;
    ull f = 2;
    while (f * f <= n)
    {
        while (n % f == 0)
        {
            factors[f]++;
            n /= f;
        }
        f++;
    }
    if (n > 1) factors[n]++;
    return factors;
}

int getf(int x) {return fa[x] == x ? x : fa[x] = getf(fa[x]);}

typedef long double db;
const db eps=1e-12;

struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    Point operator / (const db &t)const
    {
        return Point(x/t,y/t);
    }
    bool operator < (const Point &t)const
    {
        return fabs(x-t.x)<eps ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return fabs(x-t.x)<eps && fabs(y-t.y)<eps;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    Point rot90()const
    {
        return Point(-y,x);
    }
};

struct Circle
{
    Point o;
    db r;
    Circle(){}
    Circle(Point _o,db _r):o(_o),r(_r){}
    friend vector<Point> operator & (const Circle &c1,const Circle &c2)
    {
        db d=(c1.o-c2.o).len();
        if(d>c1.r+c2.r+eps || d<fabs(c1.r-c2.r)-eps)
            return vector<Point>();
        db dt=(c1.r*c1.r-c2.r*c2.r)/d,d1=(d+dt)/2;
        Point dir=(c2.o-c1.o)/d,pcrs=c1.o+dir*d1;
        dt=sqrt(max(0.0L,c1.r*c1.r-d1*d1)),dir=dir.rot90();
        return vector<Point>{pcrs+dir*dt,pcrs-dir*dt};
    }
};

struct DSU
{
    int fa[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x!=y)fa[x]=y;
    }
}dsu;


typedef long long LL;
const int MAXN=1e5+5;
const LL INF=2e18;
//const int INF=0x3f3f3f3f;//根据是否超long long修改
LL a[MAXN];

//线段树节点结构体
struct Node{
    int left,right;//左右边界
    LL mi,ma;//最小值 最大值
    LL sum;//和
    LL add;//增减标记
    int set;//重置标记
}tree[MAXN*4];//空间开四倍

//向上更新
void PushUp(int rt){
    int lson=rt<<1,rson=rt<<1|1;
    tree[rt].mi=min(tree[lson].mi,tree[rson].mi);
    tree[rt].ma=max(tree[lson].ma,tree[rson].ma);
    tree[rt].sum=tree[lson].sum+tree[rson].sum;
}

//向下传递标记
void PushDown(int rt){
    if(tree[rt].left<tree[rt].right){//如果不是叶子
        int lson=rt<<1,rson=rt<<1|1;
        if(tree[rt].set!=-1){//set初始为一个不会重置到的数，这里是-1
            tree[lson].set=tree[rt].set;tree[rson].set=tree[rt].set;
            tree[lson].add=tree[rson].add=0;//add失效
            tree[lson].mi=tree[rson].mi=tree[rt].set;
            tree[lson].ma=tree[rson].ma=tree[rt].set;
            tree[lson].sum=(LL)tree[rt].set*(tree[lson].right-tree[lson].left+1);
            tree[rson].sum=(LL)tree[rt].set*(tree[rson].right-tree[rson].left+1);
            tree[rt].set=-1;
        }
        if(tree[rt].add){
            tree[lson].add+=tree[rt].add;tree[rson].add+=tree[rt].add;
            tree[lson].mi+=tree[rt].add;tree[rson].mi+=tree[rt].add;
            tree[lson].ma+=tree[rt].add;tree[rson].ma+=tree[rt].add;
            tree[lson].sum+=(LL)tree[rt].add*(tree[lson].right-tree[lson].left+1);
            tree[rson].sum+=(LL)tree[rt].add*(tree[rson].right-tree[rson].left+1);
            tree[rt].add=0;
        }
    }
}

//建立函数
void Build(int rt,int L,int R){
    tree[rt].left=L;tree[rt].right=R;tree[rt].add=0;tree[rt].set=-1;
    if(L==R) {tree[rt].sum=tree[rt].mi=tree[rt].ma=a[L]; return;}
    int mid=(tree[rt].left+tree[rt].right)>>1;
    Build(rt<<1,L,mid);//只有Build时LR才会变
    Build(rt<<1|1,mid+1,R);
    PushUp(rt);
}

LL QuerySum(int rt,int L,int R){
    if(R<tree[rt].left||L>tree[rt].right) return  0;
    if(L<=tree[rt].left&&tree[rt].right<=R)  return tree[rt].sum;
    PushDown(rt);
    int mid=(tree[rt].left+tree[rt].right)>>1;
    LL res=0;
    if(L<=mid)  res+=QuerySum(rt<<1,L,R);
    if(R>mid)   res+=QuerySum(rt<<1|1,L,R);
    PushUp(rt);
    return  res;
}

LL QueryMin(int rt,int L,int R){
    if(L<=tree[rt].left&&tree[rt].right<=R) return tree[rt].mi;
    PushDown(rt);
    int mid=(tree[rt].left+tree[rt].right)>>1;
    LL res=INF;
    if(L<=mid) res=min(res,QueryMin(rt<<1,L,R));
    if(R>mid) res=min(res,QueryMin(rt<<1|1,L,R));
    PushUp(rt);
    return  res;
}

LL QueryMax(int rt,int L,int R){
    if(L<=tree[rt].left&&tree[rt].right<=R) return  tree[rt].ma;//完全包含才产生贡献
    PushDown(rt);
    int mid=(tree[rt].left+tree[rt].right)>>1;
    LL res=-INF;
    if(L<=mid) res=max(res,QueryMax(rt<<1,L,R));
    if(R>mid) res=max(res,QueryMax(rt<<1|1,L,R));
    PushUp(rt);
    return  res;
}

void UpdateAdd(int rt,int L,int R,int x){//把区间[L,R]加上x
    if(L<=tree[rt].left&&tree[rt].right<=R){
        tree[rt].add+=x;
        tree[rt].sum+=(LL)x*(tree[rt].right-tree[rt].left+1);
        tree[rt].mi+=x;tree[rt].ma+=x;
        return;
    }
    PushDown(rt);
    int mid=(tree[rt].left+tree[rt].right)>>1;
    if(L<=mid) UpdateAdd(rt<<1,L,R,x);
    if(R>mid) UpdateAdd(rt<<1|1,L,R,x);
    PushUp(rt);
}

void Display(int rt){
    cout<<"-------------"<<endl;
    cout<<"id: "<<rt<<endl;
    cout<<"["<<tree[rt].left<<","<<tree[rt].right<<"]"<<endl;
    cout<<"mi: "<<tree[rt].mi<<endl;
    cout<<"ma: "<<tree[rt].ma<<endl;
    cout<<"sum: "<<tree[rt].sum<<endl;
    cout<<"add: "<<tree[rt].add<<endl;
    cout<<"set: "<<tree[rt].set<<endl;
}

void bfs(int rt){
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(rt);
    while(!q.empty()){
        int fst=q.front();
        q.pop();
        Display(fst);
        if(tree[fst].right>tree[fst].left){
            q.push(fst<<1);
            q.push(fst<<1|1);
        }
    }
}

void UpdateSet(int rt,int L,int R,int x){//把区间[x,y]置为x
    if(L<=tree[rt].left&&tree[rt].right<=R){
        tree[rt].set=x;
        tree[rt].sum=(LL)x*(tree[rt].right-tree[rt].left+1);
        tree[rt].mi=x;tree[rt].ma=x;
        tree[rt].add=0;
        return;
    }
    PushDown(rt);
    int mid=(tree[rt].left+tree[rt].right)>>1;
    if(L<=mid) UpdateSet(rt<<1,L,R,x);
    if(R>mid){
        UpdateSet(rt<<1|1,L,R,x);
    }
    PushUp(rt);
}

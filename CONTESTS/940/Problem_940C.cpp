#include <bits/stdc++.h>
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
typedef vector<int> VI;
typedef pair<int,int> PII;
const ll mod = 1000000007;
const ll mod2inv = 500000004;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll powmod(ll a,ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}
int x[200];
char a[100005];
int n, k, l, r;


int main()
{
    FAST;
    cin >> n >> k >> a;
    rep(i, 0, n)
        x[(int)a[i]] = 1;
    rep_(i, 'a', 'z')
    {
        if (x[i])
        {
            if (!l)
                l = i;
            if (r)
                x[r] = i;
            r = i;
        }
    }
    x[r] = -1;
    if (k > n)
    {
        cout << a;
        while (k > n) {
            cout << (char)l;
            k--;
        }
        cout << endl;
        return 0;
    }
    else
    {
        a[k] = '\0';
        per(i, 0, k)
        {
            if (a[i] == r)
                a[i] = l;
            else
            {
                a[i] = x[(int)a[i]];
                break;
            }
        }
        cout << a << endl;
    }
    return 0;
}

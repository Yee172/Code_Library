#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 1000005
#define REP(start, end, step) for (int __i__ = (start); __i__ < (end); __i__ += (step))
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
ll A[MAXN];
ll B[MAXN];


int main(int argc, char const *argv[])
{
    fast;
    ll T, _;
    cin >> T;
    REP(0, T, 1)
    {
        ll n, m, p, a, b, r = INF, s = 0, t;
        cin >> n >> m >> p;
        for (_ = 0; _ < n; _++)
            cin >> A[_];
        for (_ = 0; _ < p; _++)
        {
            cin >> a >> b;
            B[_] = (m + A[a - 1] - b % m) % m;
            s += B[_];
        }
        sort(B, B + p);
        for (_ = 0; _ < p; _++)
        {
            t = s + _ * (m - B[_]) - (p - _) * B[_];
            r = min(r, t);
        }
        cout << r << endl;
    }
    return 0;
}

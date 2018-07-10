#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define MAXN 2000500
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
int T;
ull p, l;

namespace Vince
{
    void solve(int T)
    {
        cin >> p >> l;
        p -= l;
        bool t = 1;
        set<ull> factors;
        set<ull>::iterator iter;
        for (ull i = 1; i * i <= p; i++) if (p % i == 0) factors.insert(i), factors.insert(p / i);
        for (iter = factors.begin(); iter != factors.end(); iter++) if (*iter > l) cout << " " << *iter , t = 0;
        if (t) cout << " impossible";
    }
}

using namespace Vince;
int main()
{
    FAST;
    cin >> T;
    rep(_, 1, T) cout << "Case " << _ << ":", solve(T), cout << endl;
    return 0;
}

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
    ll T;
    cin >> T;
    REP(0, T, 1)
    {
        int n, m;
        cin >> n >> m;
        char t;
        cin >> t;
        int lR = 0, rL = 0;
        REP(1, m - 1, 1)
        {
            cin >> t;
            if (t == 'R')
                lR++;
        }
        cin >> t;
        if (t == 'L')
            rL++;
        if (t == 'R')
            lR++;
        REP(m, n - 1, 1)
        {
            cin >> t;
            if (t == 'L')
                rL++;
        }
        cin >> t;
        cout << min(lR, rL) << endl;
    }
    return 0;
}

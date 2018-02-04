#include <bits/stdc++.h>
#define MAXN 200005
#define REP(start, end, step) for (int $i = (start); $i < (end); $i += (step))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
using namespace std;
int a[MAXN];
char b[MAXN];


int main(int argc, char const *argv[])
{
    FAST;
    a[0] = -1;
    b[0] = '0';
    int n, m, M, bm, bM;
    cin >> n;
    REP(1, n + 1, 1)
        cin >> a[$i];
    REP(1, n, 1)
        cin >> b[$i];
    m = inf;
    M = 0;
    bm = bM = 1;
    REP(1, n, 1)
    {
        if (a[$i] < m)
            m = a[$i];
        if (a[$i] > M)
            M = a[$i];
        if (b[$i] == '0')
        {
            if (bm != m || bM != M)
            {
                cout << "NO" << endl;
                return 0;
            }
            bm = $i + 1;
            bM = $i + 1;
            m = inf;
            M = 0;
            if (b[$i - 1] == '0')
            {
                if (a[$i] != $i)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        if (b[$i] == '1')
        {
            bM++;
        }
    }
    cout << "YES" << endl;



    return 0;
}

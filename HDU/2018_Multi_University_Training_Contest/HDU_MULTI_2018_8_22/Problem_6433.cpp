#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

#ifdef Yee_172
#include "template/tools/local_test.hpp"
#else
#define _______ ;
#define _debug(...) ;
#endif

typedef long long ll;
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t, n;
    for (cin >> t; t--; ) cin >> n, cout << fixed << setprecision(0) << pow(2, n) << endl;
    return 0;
}

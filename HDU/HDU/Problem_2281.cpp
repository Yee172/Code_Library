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

const ll inf = 1000000000000000001;
ll n[] = {1, 337, 65521, 12710881, 2465845537, 478361323441, 92799630902161, 18002650033695937, inf};
ll x[] = {1, 195, 37829, 7338631, 1423656585, 276182038859, 53577891882061, 10393834843080975};

int main()
{
    ll N;
    while (~scanf("%lld", &N) && N)
    {
        int r = 0;
        for (int i = 1; ; ++i) if (n[i] > N)
            {
                r = i - 1;
                break;
            }
        printf("%lld %lld\n", n[r], x[r]);
    }
    return 0;
}

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

int gen[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int x, k, y;

int main()
{
    int t;
    for (scanf("%d", &t); t--; )
    {
        scanf("%d%d", &x, &k);
        while (x && k)
        {
            y = 0;
            while (x)
            {
                y += gen[x % 10];
                x /= 10;
            }
            x = y;
            --k;
        }
        if (k) x = k & 1;
        printf("%d\n", x);
    }
    return 0;
}

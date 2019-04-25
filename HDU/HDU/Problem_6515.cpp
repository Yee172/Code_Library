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

char c[300005];
int w;
bool tmp[24];

int main()
{
    scanf("%s", c);
    for (int i = 0, l = (int) strlen(c); i < l; i += 3)
    {
        for (int j = 0; j < 3; ++j)
        {
            w = (int) c[i + j];
            for (int k = 0; k < 8; ++k)
            {
                tmp[j << 3 | k] = (bool) (w & 1);
                w >>= 1;
            }
        }
        for (int j = 0; j < 4; ++j)
        {
            w = 0;
            for (int k = 0; k < 6; ++k)
            {
                w <<= 1;
                w |= tmp[6 * j + k];
            }
            printf("%d ", w);
        }
    }
    return 0;
}

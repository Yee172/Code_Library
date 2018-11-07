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

const int MAXN = 10050;
int n;
inline int __add__(int a, const int b)
{
    a += b;
    return a < n ? a : a - a / n * n;
}
int a[MAXN];
int b[MAXN];
int exist[MAXN];

int main()
{
    scanf("%d", &n);
    _rep(i, n)
    {
        scanf("%d", a + i);
        b[i] = __add__(a[i], b[i - 1]);
        if (exist[b[i]])
        {
            printf("%d\n", i - exist[b[i]]);
            for (int j = exist[b[i]] + 1; j <= i; ++j) printf("%d\n", a[j]);
            break;
        }
        if (!b[i])
        {
            printf("%d\n", i);
            _rep(j, i) printf("%d\n", a[j]);
            break;
        }
        exist[b[i]] = i;
    }
    return 0;
}

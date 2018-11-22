#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <time.h>
#include <vector>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <complex>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
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

char s[30];
int d[30];
int cnt[30];
bool vis[30];

int main()
{
    int t, num;
    bool ok;
    for (scanf("%d", &t); t--; )
    {
        scanf("%s", s);
        for (int i = 0; i < 26; ++i) d[i] = s[i] - 'A';
        memset(cnt, 0, sizeof cnt);
        memset(vis, false, sizeof vis);
        for (int i = 0; i < 26; ++i)
            if (!vis[i])
            {
                num = 0;
                for (int j = d[i]; !vis[j]; vis[j] = true, j = d[j], ++num);
                ++cnt[num];
            }
        ok = true;
        for (int i = 2; i <= 26; ++(++i)) ok &= cnt[i] & 1 ^ 1;
        puts(ok ? "Yes" : "No");
    }
    return 0;
}

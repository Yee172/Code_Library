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

vector<vector<int> > gao;
char buffer[1 << 20];
int n;
int res;
void dfs(const int i)
{
    if (i == n - 2)
    {
        int p = gao[i][0] + gao[i][1] + gao[i][2] + gao[i][3];
        if (p == 3) res += 6;
        else if (p) res += 4;
        return;
    }
    if (i == n - 1)
    {
        if (gao[i][0] | gao[i][1]) res += 2;
        return;
    }
    for (int j = 0; j < (1 << n - i); j += 2)
    {
        gao[i + 1][j / 2] = gao[i][j] & gao[i][j | 1];
    }
    dfs(i + 1);
    for (int j = 0; j < (1 << n - i); j += 2)
    {
        gao[i + 1][j / 2] = gao[i][j] | gao[i][j | 1];
    }
    dfs(i + 1);
    for (int j = 0; j < (1 << n - i); j += 2)
    {
        gao[i + 1][j / 2] = gao[i][j] ^ gao[i][j | 1];
    }
    dfs(i + 1);
}

void Main()
{
    scanf("%d", &n);
    res = 0;
    gao.resize(n);
    rep(i, n) gao[i].resize(1 << n - i);
    scanf("%s", buffer);
    rep(i, 1 << n) gao[0][i] = buffer[i] == '1';
    dfs(0);
    printf("%d\n", res);
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

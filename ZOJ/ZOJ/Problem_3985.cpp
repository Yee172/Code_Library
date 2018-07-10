#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 1000005
#define REP(start, end, step) for (int __i__ = (start); __i__ < (end); __i__ += (step))
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
char str[MAXN];


int main(int argc, char const *argv[])
{
    fast;
    int T;
    scanf("%d", &T);
    REP(0, T, 1)
    {
        int n, r = 0, add = 1;
        string s, temp;
        scanf("%d", &n);
        str[0] = getchar();
        while (str[0] != 'C' && str[0] != 'P')
            str[0] = getchar();
        for (int i = 1; i < n; i++)
            str[i] = getchar();
        str[n] = '\0';
        s = str;
        for (int i = 0; i < n - 2; i++)
        {
            if (i + 5 <= n && s.substr(i, 5) == "CCCPC")
            {
                r++;
                i += 3;
                continue;
            }
            if (i + 4 <= n && s.substr(i, 4) == "CCPC")
            {
                r++;
                i += 2;
                continue;
            }
            if (add)
            {
                temp = s.substr(i, 3);
                if (temp == "CCP" || temp == "CCC" || temp == "CPC")
                    add = 0;
            }
        }
        printf("%d\n", r + 1 - add);
    }
    return 0;
}

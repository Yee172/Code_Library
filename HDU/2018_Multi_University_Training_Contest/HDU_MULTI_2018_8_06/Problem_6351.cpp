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
typedef pair<int, int> pii;
#define fi first
#define se second
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define _rep(i, n) for (int (i) = 1; (i) <= (n); (i)++)

char n[12], tmp[12];
inline int str2num(const char * str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++) res = (res << 1) + (res << 3) + (str[i] ^ 48);
    return res;
}

inline void num2str(const int number)
{
    char c[12];
    int num = number, cnt = 0;
    for (int m = 10; num; num /= m) c[cnt++] = num % m + 48;
    tmp[cnt] = '\0';
    for (int i = 0; cnt--; i++) tmp[cnt] = c[i];
}

void Main()
{
    int t, k;
    for (scanf("%d", &t); t--; )
    {
        scanf("%s%d", n, &k);
        int len = strlen(n);
        int nn = str2num(n);
        int maximum, minimum;
        maximum = minimum = nn;
        queue<pii> q;
        q.push(make_pair(nn, k));
        while (!q.empty())
        {
            int next = q.front().fi;
            int move = q.front().se;
            q.pop();
            if (move < 0) break;
            maximum = next > maximum ? next : maximum;
            minimum = next < minimum ? next : minimum;
            if (move == 0) continue;
            num2str(next);
            rep(i, len)
                for (int j = i + 1; j < len; j++)
                {
                    swap(tmp[i], tmp[j]);
                    if (tmp[0] != 48)
                    {
                        int a = str2num(tmp);
                        if (a > maximum || a < minimum) q.push(make_pair(a, move - 1));
                    }
                    swap(tmp[i], tmp[j]);
                }
        }
        printf("%d %d\n", minimum, maximum);
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

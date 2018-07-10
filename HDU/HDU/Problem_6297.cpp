#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
char rankk[20];
char name[20];
char prob[20];
char state[20];
ll running;

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...)
#endif

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%s%s%s%s", rankk, name, prob, state);
        ll rank_len = (ll) strlen(rankk);
        ll name_len = (ll) strlen(name);
        ll prob_len = (ll) strlen(prob);
        ll state_len = (ll) strlen(state);
        rep(i, 3 - rank_len) putchar(' ');
        printf("%s|%s", rankk, name);
        rep(i, 16 - name_len) putchar(' ');
        printf("|%s|[", prob);
        if (state_len == 7)
        {
            scanf("%lld", &running);
            rep(i, running) putchar('X');
            rep(i, 10 - running) putchar(' ');
        }
        else
        {
            if (state[0] == 'F' && state[1] == 'B')
                state[0] = 'A', state[1] = 'C', state[2] = '*', state[3] = '\0', state_len = 3;
            rep(i, 4) putchar(' ');
            printf(state);
            rep(i, 6 - state_len) putchar(' ');
        }
        puts("]");
    }
    return 0;
}

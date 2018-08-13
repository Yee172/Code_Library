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
#define rep(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define _rep(i, n) for (int (i) = 1; (i) <= (n); ++(i))
#define fi first
#define se second

namespace fast_io
{
    namespace fast_io_head
    {
        const int __FREAD_BUFFER_SIZE__ = 1 << 20;
        char __BUFFER__[__FREAD_BUFFER_SIZE__], *__P1__=__BUFFER__, *__P2__=__BUFFER__;
#define __IF_END__ (__P1__ == __P2__)
#define __READ_ONE__ (fread(__BUFFER__, 1, __FREAD_BUFFER_SIZE__, stdin))
#define __GET_CHAR__ (__IF_END__ && (__P2__ = (__P1__ = __BUFFER__) + __READ_ONE__, __IF_END__) ? -1 : *__P1__++)
        template <typename T>
        inline bool read(T &x)
        {
            char c;
            bool f = false;
            for (c = __GET_CHAR__; !isdigit(c); c = __GET_CHAR__)
            {
                if (c == EOF) return false;
                if (c == '-') f = true;
            }
            for (x = 0; isdigit(c); c = __GET_CHAR__) x = (x << 1) + (x << 3) + (c ^ 48);
            if (f) x = -x;
            return true;
        }
    }
    using fast_io_head::read;

    template <typename A, typename B>
    inline bool read(A &a, B&b) { return read(a) && read(b); }
}

using fast_io::read;

#define MAXM 5
#define MAXN 100005
int ability[MAXM], gao;
pii monster[MAXM][MAXN];
int add[MAXM][MAXN];
int cnt[MAXM];
unordered_map<int, int> win;

void Main()
{
    int t, n, k;
    for (read(t); t--; )
    {
        gao = 0;
        win.clear();
        read(n, k);
        rep(i, k) read(ability[i]);
        rep(i, n)
        {
            rep(j, k) read(monster[j][i].fi), monster[j][i].se = i;
            rep(j, k) read(add[j][i]);
        }
        rep(j, k) sort(monster[j], monster[j] + n), cnt[j] = 0;
        int ok = 5;
        while (ok)
        {
            rep(i, k)
            {
                for (; monster[i][cnt[i]].fi <= ability[i] && cnt[i] < n; ++cnt[i])
                {
                    int id = monster[i][cnt[i]].se;
                    ++win[id];
                    if (win[id] == k)
                    {
                        rep(j, k) ability[j] += add[j][id];
                        ++gao;
                        ok = 5;
                    }
                }
            }
            --ok;
        }
        printf("%d\n", gao);
        rep(i, k) printf("%d%c", ability[i], i == k - 1 ? '\n' : ' ');
    }
}

signed main()
{
    _______
    Main();
    _______
    return 0;
}

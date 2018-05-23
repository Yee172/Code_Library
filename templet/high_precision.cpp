#include <bits/stdc++.h>
using namespace std;
#define MAXN 10050

char sa[MAXN], sb[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
void add(char* sa, char* sb)
{
    int la = strlen(sa);
    int lb = strlen(sb);
    int lc = max(la, lb);
    for (int i = 0; i < la; i++) a[la - i - 1] = sa[i] - '0';
    for (int i = 0; i < lb; i++) b[lb - i - 1] = sb[i] - '0';
    for (int i = 0; i < lc; i++)
    {
        c[i] = a[i] + b[i] + c[i];
        while (c[i] >= 10) c[i + 1]++, c[i] -= 10;
    }
    while (c[lc] > 0)
    {
        while (c[lc] >= 10) c[lc + 1]++, c[lc] -= 10;
        lc++;
    }
    for (int i = lc - 1; i >= 0; i--) printf("%d", c[i]);
    puts("");
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
}

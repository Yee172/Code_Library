#ifndef NORMAL
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#else
#include <bits/stdc++.h>
#endif
#pragma optimize("Ofast")
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; (i) < (n); (i)++)
#define _rep(i, n) for (ll i = 1; (i) <= (n); (i)++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define square(x) ((x) * (x))

template <typename T>
inline bool read(T &x)
{
    char c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar())
    {
        if (c == EOF) return false;
        if (c == '-') f = true;
    }
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    if (f) x = -x;
    return true;
}

template <typename A, typename B>
inline bool read(A &a, B&b)
{
    return read(a) && read(b);
}

template <typename A, typename B, typename C>
inline bool read(A &a, B &b, C &c)
{
    return read(a) && read(b) && read(c);
}

template <typename A, typename B, typename C, typename D>
inline bool read(A &a, B &b, C &c, D &d)
{
    return read(a) && read(b) && read(c) && read(d);
}

#ifdef VinceBlack
#define _debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define _debug(...) ;
#endif

const ll N = 105;
const ll M = 205;
const double inf = 1e20;

struct edge
{
    ll v;
    double w;
    double c;
    edge * next;
}e[M];

ll top;
edge * adjacency_list[N];

inline void insert_edge(ll u, ll v, double w, double c)
{
    e[top].v = v;
    e[top].w = w;
    e[top].c = c;
    e[top].next = adjacency_list[u];
    adjacency_list[u] = &e[top++];
}

ll n, m, s, a, b;
double v, r, c;
double dis[N];
ll vis[N];
bool spfa(ll st, ll n)
{
    queue<ll> q;
    for (ll i = 1; i <= n; ++i)
    {
        dis[i] = 0;
        vis[i] = 0;
    }
    q.push(st);
    dis[st] = v;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (edge * t = adjacency_list[u]; t; t = t->next)
        {
            ll v = t->v;
            double w = t->w;
            double c = t->c;
            double tmp = (dis[u] - c) * w;
            if (dis[v] < tmp)
            {
                dis[v] = tmp;
                vis[v]++;
                if (vis[v] > n) return true;
                q.push(v);
            }
        }
    }
    return dis[st] > v;
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    while (read(n, m, s) && scanf("%lf", &v))
    {
        top = 0;
        _rep(i, n) adjacency_list[i] = NULL;
        rep(i, m)
        {
            read(a, b);
            scanf("%lf%lf", &r, &c);
            insert_edge(a, b, r, c);
            scanf("%lf%lf", &r, &c);
            insert_edge(b, a, r, c);
        }
        puts(spfa(s, n) ? "YES" : "NO");
    }
    return 0;
}

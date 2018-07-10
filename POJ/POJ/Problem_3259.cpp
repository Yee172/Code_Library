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

const ll N = 505;
const ll M = 5505;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    ll v;
    ll w;
    edge * next;
}e[M];

ll top;
edge * adjacency_list[N];

inline void insert_edge(ll u, ll v, ll w)
{
    e[top].v = v;
    e[top].w = w;
    e[top].next = adjacency_list[u];
    adjacency_list[u] = &e[top++];
}

inline void insert_edge_double(ll u, ll v, ll w)
{
    insert_edge(u, v, w);
    insert_edge(v, u, w);
}

ll dis[N];
ll vis[N];
bool spfa(ll st, ll n)
{
    queue<ll> q;
    for (ll i = 1; i <= n; ++i)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    q.push(st);
    dis[st] = 0;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (edge * t = adjacency_list[u]; t; t = t->next)
        {
            ll v = t->v;
            ll w = t->w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                vis[v]++;
                if (vis[v] > n) return true;
                q.push(v);
            }
        }
    }
    return dis[st] < 0;
}

ll n, m, W, u, v, w;
signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    read(n);
    while (read(n, m, W))
    {
        top = 0;
        _rep(i, n) adjacency_list[i] = NULL;
        rep(i, m) read(u, v, w), insert_edge_double(u, v, w);
        rep(i, W) read(u, v, w), insert_edge(u, v, -w);
        puts(spfa(1, n) ? "YES" : "NO");
    }
    return 0;
}

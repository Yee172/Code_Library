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

#define N 205
ll t;

struct point
{
    ll x, y;
};

inline double dist(point a, point b)
{
    return sqrt(square(a.x - b.x) + square(a.y - b.y));
}

point a[N];
double dp[N][N];
double dis[N];
bool vis[N];
double dij(ll st, ll n, ll end)
{
    for (ll i = 1; i <= n; i++) dis[i] = 1e20, vis[i] = 0;
    priority_queue<pair<double, ll> > q;
    q.push(make_pair(dis[st] = 0, st));
    while (!q.empty())
    {
        ll u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        _rep(i, n)
        {
            double w = dp[u][i];
            if (dis[i] > max(dis[u], w))
            {
                dis[i] = max(dis[u], w);
                q.push(make_pair(- dis[i], i));
            }
        }
    }
    return dis[end];
}


void solve(ll n)
{
    _rep(i, n) read(a[i].x, a[i].y);
    _rep(i, n) _rep(j, i - 1) dp[i][j] = dp[j][i] = dist(a[i], a[j]);
    printf("Scenario #%lld\nFrog Distance = %.3f\n\n", ++t, dij(1, n, 2));
}

signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll n;
    while (read(n) && n) solve(n);
    return 0;
}

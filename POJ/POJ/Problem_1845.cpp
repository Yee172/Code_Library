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

#define MOD 9901

ll powmod(ll a,ll b) {ll r = 1; a %= MOD; for(; b; b >>= 1) {if (b & 1) r = r * a % MOD; a = a * a % MOD;} return r;}
ll inv(ll x) {return powmod(x, MOD - 2);}

map<ll, ll> generate_factors(ll n)
{
    map<ll, ll> factors;
    ll f = 2;
    while (f * f <= n)
    {
        while (n % f == 0)
        {
            factors[f]++;
            n /= f;
        }
        f++;
    }
    if (n > 1) factors[n]++;
    return factors;
}

ll t;
signed main()
{
#ifdef Yee_172
    freopen("../in.txt", "r", stdin);
#endif
    ll a, b;
    while (read(a, b))
    {
        ll res = 1;
        map<ll, ll> factors = generate_factors(a);
        for (map<ll, ll>::iterator it = factors.begin(); it != factors.end(); it++)
        {
            ll tmp = (it->fi - 1) % MOD ? (powmod(it->fi, it->se * b + 1) + MOD - 1) * inv(it->fi - 1) : it->se * b + 1;
            res *= tmp % MOD;
            res %= MOD;
            res += MOD;
            res %= MOD;
        }
        printf("%lld\n", res);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll inv = 500000004;
ll pm(ll a, ll b) {ll r = 1; a %= mod; for(; b; b >>= 1) {if (b & 1) r = r * a % mod; a = a * a % mod;} return r;}
ll a[5001];
ll n, k, i, j, r, p;
int main()
{
    cin >> n >> k;
    a[0] = 1;
    p = pm(2, n);
    for(i = 0; i < k; i++) for (j = i; j >= 0; a[j] = a[j] * j % mod, j--) a[j + 1] = (a[j + 1] + a[j] * (n - j)) % mod;
    for(i = 0; i <= k; i++, p = p * inv % mod) r = (r + p * a[i]) % mod;
    cout << r;
    return 0;
}

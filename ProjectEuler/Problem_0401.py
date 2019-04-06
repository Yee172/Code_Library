# Let sigma2(n) represent the sum of the squares of
# the divisors of n.
# Let SIGMA2 represent the summatory function of sigma2.
# Find SIGMA2(10^{15}) modulo 10^{9}.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 15
MOD = 10 ** 9

r = 0
middle = int(MAXN ** .5)

for d in range(1, middle):
    r += d * d * (MAXN // d)

d = middle
while d <= MAXN:
    x = MAXN // d
    y = MAXN // x
    r += (y * (y + 1) * (2 * y + 1) - d * (d - 1) * (2 * d - 1)) // 6 * x
    d = y + 1

print(r % MOD)

# How many fractions lie between 1 / 3 and 1 / 2 in the
# sorted set of reduced proper fractions for d \leq 12,000?
# ----------------------------------------------------
# Analysis: brute force

from math import gcd

MAXN = 12000
r = 0
for i in range(5, MAXN + 1):
    for j in range(i // 3 + 1, i + 1 >> 1):
        if gcd(i, j) == 1:
            r += 1

print(r)

# By listing the set of reduced proper fractions for
# d \leq 1000000 in ascending order of size, find the
# numerator of the fraction immediately to the left
# of 3 / 7.
# ----------------------------------------------------
# Analysis: brute force

from math import gcd

x = 3 / 7
res = (0, 0, 0)
for i in range(10, 10 ** 6 + 1):
    j = int(i * x) + 1
    for k in range(j - 2, j):
        if gcd(k, i) == 1 and res[0] < k / i:
            res = (k / i, k, i)

print(res)

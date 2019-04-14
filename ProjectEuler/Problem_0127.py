# The radical of n, rad(n), is the product of the distinct prime factors of n.
# We shall define the triplet of positive integers (a, b, c) to be an abc-hit if:
#    1. gcd(a, b) = gcd(a, c) = gcd(b, c) = 1
#    2. a < b
#    3. a + b = c
#    4. rad(a b c) < c
# Find \sum c for c < 120000.
# ----------------------------------------------------
# Analysis: brute force
#           Notice that gcd(a, b) = gcd(a, c) = gcd(b, c) = 1
#           leads to that rad(a b c) = rad(a) rad(b) rad(c)

import numpy as np
from math import gcd

from ProjectEuler.lib.prime_sieve import prime_sieve

MAXN = 120000
prime = prime_sieve(MAXN)

rad = np.ones(MAXN, dtype=np.int64)
for p in prime:
    rad[p:MAXN:p] *= p

sorted_rad_index = np.array(sorted(range(MAXN), key=lambda i: rad[i]))

r = 0
for c in range(3, MAXN):
    for a in sorted_rad_index[1:]:
        if rad[a] * rad[c] >= c + 1 >> 1:
            break
        if a >= c + 1 >> 1:
            continue
        b = c - a
        if gcd(b, a) == 1 and rad[a] * rad[b] * rad[c] < c:
            r += c

print(r)

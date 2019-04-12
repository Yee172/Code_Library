# The radical of n, rad(n), is the product of the distinct prime factors of n.
# Let E(k) be the kth element in the sorted n column;
#    for example, E(4) = 8 and E(6) = 9.
# If rad(n) is sorted for 1 \leq n \leq 100000, find E(10000).
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 100000 + 1
prime = prime_sieve(MAXN)
rad = [1] * MAXN
for p in prime:
    for i in range(p, MAXN, p):
        rad[i] *= p

print(sorted(zip(rad, range(MAXN)))[10000][1])

# What is the smallest odd composite that cannot be
# written as the sum of a prime and twice a square?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 20000
not_visited, prime = prime_sieve(MAXN, False)

for p in prime[1:]:
    t = 1
    p += 2
    while p < MAXN:
        not_visited[p] = True
        t += 1
        p += 4 * t - 2

print(min(x for x in range(3, MAXN, 2) if not not_visited[x]))

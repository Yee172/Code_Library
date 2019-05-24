# For two distinct primes p and q let M(p, q, N) be the
# largest positive integer \leq N only divisible by both
# p and q and M(p, q, N) = 0 if such a positive integer
# does not exist.
# Let S(N) be the sum of all distinct M(p, q, N).
# Find S(10000000).
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 7 + 1
prime = prime_sieve(MAXN >> 1)
res = 0
for i in range(len(prime)):
    p = prime[i]
    for j in range(i):
        q = prime[j]
        if p * q >= MAXN:
            break
        t = MAXN // p // q
        possible = [1]
        s = 1
        while s <= t:
            n = s
            while n <= t:
                n *= q
            possible.append(n // q)
            s *= p
        res += max(possible) * p * q

print(res)

# How many composite integers, n < 10_{8}, have precisely
# two, not necessarily distinct, prime factors?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 8
is_prime, prime = prime_sieve(MAXN, False, raw_is_prime=True)
pi = [0] * MAXN
pi[2] = 1
for i in range(3, MAXN):
    if i & 1:
        pi[i] = is_prime[i >> 1]
    pi[i] += pi[i - 1]

res = 0
for p in prime:
    q = (MAXN - 1) // p
    if q < p:
        break
    res += pi[q] - pi[p - 1]

print(res)

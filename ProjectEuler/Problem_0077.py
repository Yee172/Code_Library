# What is the first value which can be written as the
# sum of primes in over five thousand different ways?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 3
expectation = 5000
prime = prime_sieve(MAXN)

def count(n, p=0):
    if not n:
        return 1
    if prime[p] > n:
        return 0
    return sum(count(n - i, p + 1) for i in range(0, n + 1, prime[p]))

for i in range(MAXN):
    if count(i) > expectation:
        break

print(i)

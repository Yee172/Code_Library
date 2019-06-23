# Find the value of n \leq 1000000 for which
# n / \varphi(n) is a maximum.
# ----------------------------------------------------
# Analysis: brute force
#           Obviously, it is better for n to have more distinct factors

from lib.prime_sieve import prime_sieve

prime = prime_sieve(10 ** 3)

MAXN = 10 ** 6
res = 1
for p in prime:
    if res * p > MAXN:
        break
    res *= p

print(res)

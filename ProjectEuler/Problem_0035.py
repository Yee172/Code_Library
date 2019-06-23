# How many circular primes are there below one million.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 6
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

cnt = 0
for x in prime:
    ok = True
    n = str(x)
    if '0' in n:
        continue
    for i in range(1, len(n)):
        ok &= is_prime(int(n[i:] + n[:i]))
    cnt += ok

print(cnt)

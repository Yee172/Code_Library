# Find the sum of the only eleven primes that are both
# truncatable from left to right and right to left.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 6
is_prime, _ = prime_sieve(MAXN, False, function_is_prime=True)

def is_truncatable(x):
    s = str(x)
    if not is_prime(int(s)):
        return False
    for i in range(1, len(s)):
        if not is_prime(int(s[i:])):
            return False
        if not is_prime(int(s[:-i])):
            return False
    return True

print(sum(i for i in range(10, 800000) if is_truncatable(i)))

# Considering 4-digit primes containing repeated digits
# it is clear that they cannot all be the same.
# But there are nine 4-digit primes containing three ones:
#    1117, 1151, 1171, 1181, 1511, 1811, 2111, 4111, 8111
# We shall say that M(n, d) represents the maximum number
# of repeated digits for an n-digit prime where d is the
# repeated digit, N(n, d) represents the number of such
# primes, and S(n, d) represents the sum of these primes.
# Find the sum of all S(10, d).
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

target = 10
at_least = 10 ** (target - 1) - 1
base = int('1' * target)
MAXN = int(10 ** (target / 2)) + 1
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

def dfs(n, i, largest_missing_index, missing_remain):
    if not missing_remain:
        return n if n > at_least and is_prime(n) else 0
    res = 0
    for p in range(largest_missing_index + 1, target - missing_remain + 1):
        for j in range(10):
            if p == target - 1 and j == 0:
                continue
            if j == i:
                continue
            res += dfs(n + (j - i) * 10 ** p, i, p, missing_remain - 1)
    return res

res = 0
for i in range(10):
    S = 0
    missing = 0 if i else 1
    while not S:
        missing += 1
        S = dfs(base * i, i, -1, missing)
    res += S

print(res)

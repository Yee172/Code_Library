# A number consisting entirely of ones is called a repunit.
# We shall define R(k) to be a repunit of length k.
# Given that n is a positive integer and GCD(n, 10) = 1,
# it can be shown that there always exists a value, k,
# for which R(k) is divisible by n, and let A(n) be the
# least such value of k.
# You are given that for all primes, p > 5, that p − 1
# is divisible by A(p).
# However, there are rare composite values for which
# this is also true.
# Find the sum of the first twenty-five composite values of
# n for which GCD(n, 10) = 1 and n − 1 is divisible by A(n).
# ----------------------------------------------------
# Analysis: brute force

from ProjectEuler.lib.prime_sieve import prime_sieve

is_prime, prime = prime_sieve(10 ** 5, False, raw_is_prime=True)
target = 25
res = []
i = 3
while True:
    i += 2
    if not i % 5 or is_prime[i >> 1]:
        continue
    p = 1
    r = 1
    while p:
        p = (p * 10 + 1) % i
        r += 1
    if not (i - 1) % r:
        res += [i]
        if len(res) >= target:
            break

print(sum(res))

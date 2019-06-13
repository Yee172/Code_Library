# There are some prime values, p, for which there exists
# a positive integer, n, such that the expression
# n^{3} + n^{2} p is a perfect cube.
# What is perhaps most surprising is that for each prime
# with this property the value of n is unique, and there
# are only four such primes below one-hundred.
# How many primes below one million have this remarkable
# property?
# ----------------------------------------------------
# Analysis: brute force
#           n^{3} + n^{2} * p = m^{3}
#           Let m = a * g, n = b * g, where g = gcd(m, n), gcd(a, b) = 1
#           then we get (a^{3} - b^{3}) * g / b^{2} = p
#           Thus, we get g = b^{2}
#                    and p = a^{3} - b^{3} = (a - b)(a^{2} + a * b + b^{2}), gcd(a, b) = 1
#           Since p is prime, we get a - b = 1, i.e. a = b + 1
#           Therefore, p = 3 * b^{2} + 3 * b + 1 and we only need to check whether p is prime

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 6
is_prime, prime = prime_sieve(MAXN, False, raw_is_prime=True)
print(sum(map(lambda p: is_prime[p >> 1], [3 * x ** 2 + 3 * x + 1 for x in range(1, int(((9 + 12 * (MAXN - 2)) ** .5 - 3) / 6) + 1)])))

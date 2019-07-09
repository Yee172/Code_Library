# A unitary divisor d of a number n is a divisor of n that
# has the property gcd(d, n / d) = 1.
# Let S(n) represent the sum of the squares of the unitary
# divisors of n.
# Find S(100000000!) modulo 1000000009.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

target = 10 ** 8
modulo = 0x3b9aca09
prime = prime_sieve(target)

result = 1
for p in prime:
    counter = 0
    t = p
    while t <= target:
        counter += target // t
        t *= p
    result *= 1 + pow(p, counter << 1, modulo)
    result %= modulo

print(result)

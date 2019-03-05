# What is the largest prime factor of
# the number 600851475143?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

prime = prime_sieve(500000)

x = 600851475143
for p in prime:
    while not x % p:
        x /= p
    if x == 1:
        print(p)
        break

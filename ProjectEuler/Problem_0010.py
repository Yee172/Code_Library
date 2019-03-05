# Find the sum of all the primes below two million.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

print(sum(prime_sieve(2000000)))

# Consider the consecutive primes p_{1} = 19 and p_{2} = 23.
# It can be verified that 1219 is the smallest number
# such that the last digits are formed by p_{1} whilst
# also being divisible by p_{2}.
# Let S be the smallest of these values of n.
# Find \sum S for every pair of consecutive primes
# with 5 \leq p_{1} \leq 1000000.
# ----------------------------------------------------
# Analysis: brute force
#           Let n satisfies that
#              p1 // 10 ** n = 0
#              p1 // 10 ** (n - 1) > 0
#           Let S = s * 10 ** n + p1, then
#              s = -p1 * (10 ** n)^{-1} (mod p2)

from lib.prime_sieve import prime_sieve

prime = prime_sieve(10 ** 6 + 5)

r = 0
head = 10
for p1, p2 in zip(prime[2:], prime[3:]):
    if p1 > head: # prime can not be the form 10 ** n
        head *= 10
    s = -p1 * pow(head, p2 - 2, p2) % p2
    r += s * head + p1

print(r)

# For a prime p, let S(p) = (\sum_{k = 1}^{5} (p - k)!) % p.
# Find \sum_{p = 1, p is prime}^{10^{8}} S(p).
# ----------------------------------------------------
# Analysis: Generalized Wilson's theorem.
#              (p - 1)! = -1 (mod p)
#              (p - 2)! =  1 (mod p)
#            2 (p - 3)! = -1 (mod p)
#            6 (p - 4)! =  1 (mod p)
#           24 (p - 5)! = -1 (mod p)
#           Then, we can get that S(p) = -3 / 8
#              -3 = k p - 3 (mod p)
#           => -3 / 8 = (k p - 3) / 8 (mod p)
#              p^{2} = 1 (mod 8) for every prime p greater than 2
#           => 3 p^{2} = 3 (mod 8) for every prime p greater than 2
#           => smallest k = 3 p % 8, such that (k p - 3) / 8 is a integer
#           => S(p) = ((3 p % 8) p - 3) / 8

from lib.prime_sieve import prime_sieve

print(sum((3 * p % 8) * p - 3 >> 3 for p in prime_sieve(10 ** 8)[2:]))

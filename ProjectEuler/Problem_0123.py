# Let p_{n} be the n-th prime: 2, 3, 5, 7, 11, ..., and
# let r be the remainder when (p_{n} − 1)^{n} + (p_{n} + 1)^{n}
# is divided by p_{n}^{2}.
# For example, when
#    n = 3, p_{3} = 5, and 4^{3} + 6^{3} = 280 \equiv 5 mod 25.
# Find the least value of n for which the remainder first exceeds 10^{10}.
# ----------------------------------------------------
# Analysis: brute force

from itertools import dropwhile
from lib.prime_sieve import prime_sieve

target = 10 ** 10
MAXN = int(target ** .5) * 10
prime = prime_sieve(MAXN)
print(dropwhile(lambda i: 2 * (i + 1) * prime[i] <= target, range(0, len(prime), 2)).__next__() + 1)

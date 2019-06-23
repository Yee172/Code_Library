# We shall say that an n-digit number is pandigital if
# it makes use of all the digits 1 to n exactly once.
# What is the largest n-digit pandigital prime
# that exists?
# ----------------------------------------------------
# Analysis: brute force
#           \sum_{n = 1}^{9} n = 45
#              => 9-digit number is divisible by 3
#           \sum_{n = 1}^{8} n = 36
#              => 8-digit number is divisible by 3
#           \sum_{n = 1}^{6} n = 21
#              => 6-digit number is divisible by 3
#           \sum_{n = 1}^{5} n = 15
#              => 5-digit number is divisible by 3
#           brute force the remaining

from itertools import permutations
from lib.prime_sieve import prime_sieve

MAXN = 10 ** 5
is_prime, _ = prime_sieve(MAXN, False, function_is_prime=True)

res = 0
for k in [4, 7]:
    n = 0
    for i in range(1, k + 1):
        n = n * 10 + i
    s = str(n)
    for i in permutations(s):
        x = int(''.join(i))
        if is_prime(x):
            res = x

print(res)

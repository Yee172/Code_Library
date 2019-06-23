# The arithmetic sequence, 1487, 4817, 8147, in which
# each of the terms increases by 3330, is unusual in
# two ways:
#    (i)  each of the three terms are prime, and,
#    (ii) each of the 4-digit numbers are permutations
#         of one another.
# There are no arithmetic sequences made up of three
# 1-, 2-, or 3-digit primes, exhibiting this property,
# but there is one other 4-digit increasing sequence.
# What 12-digit number do you form by concatenating
# the three terms in this sequence?
# ----------------------------------------------------
# Analysis: brute force

from itertools import combinations, permutations, product
from lib.prime_sieve import prime_sieve

MAXN = 10000
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

res = set()
for c in product(*(['0123456789'] * 4)):
    possible = []
    for p in permutations(c):
        p = int(''.join(p))
        if is_prime(p) and p > 999:
            possible.append(p)
    possible = sorted(list(set(possible)))
    if len(possible) < 3:
        continue
    for d in combinations(possible, 3):
        if d[2] + d[0] == d[1] << 1:
            res.add(d)

for r in res:
    print(*r, sep='')

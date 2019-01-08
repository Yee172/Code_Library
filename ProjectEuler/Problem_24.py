# What is the millionth lexicographic permutation of
# the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
# ----------------------------------------------------
# Analysis: brute force

from itertools import permutations
digits = '0123456789'

MAXN = 10 ** 6
i = 0
for p in permutations(digits):
    i += 1
    if i == MAXN:
        print(''.join(p))
        break

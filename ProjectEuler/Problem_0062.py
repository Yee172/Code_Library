# Find the smallest cube for which exactly five
# permutations of its digits are cube.
# ----------------------------------------------------
# Analysis: brute force

from collections import defaultdict

MAXN = 10 ** 4
cube_permutation_list = defaultdict(list)
for i in range(1, MAXN):
    s = ''.join(sorted(str(i ** 3)))
    cube_permutation_list[s] += [i]

res = MAXN
for v in cube_permutation_list.values():
    if len(v) == 5:
        res = min(res, min(v))

print(res ** 3)

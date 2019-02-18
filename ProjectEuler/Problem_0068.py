# Using the numbers 1 to 10, and depending on arrangements,
# it is possible to form 16- and 17-digit strings.
# What is the maximum 16-digit string for a "magic" 5-gon ring?
# ----------------------------------------------------
# Analysis: brute force
#           10 must in the outer circle

from itertools import permutations

def check(a):
    s = 10 + a[0] + a[1]
    for i in range(1, 5):
        if a[i + 4] + a[i] + a[(i + 1) % 5] != s:
            return False
    i = min(range(4), key=lambda x: a[x + 5])
    a = list(a) + [10]
    r = []
    for j in range(5):
        k = (i + j) % 5
        r += [a[k + 5], a[(k + 1) % 5], a[(k + 2) % 5]]
    return ''.join(map(str, r))

print(max(int(check(x)) for x in permutations(range(1, 10))))

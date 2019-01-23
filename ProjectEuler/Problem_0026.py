# Find the value of d < 1000 for which 1 / d contains
# the longest recurring cycle in its decimal fraction
# part.
# ----------------------------------------------------
# Analysis: brute force

from collections import defaultdict

def f(n):
    a = 10
    p = 0
    d = defaultdict(int)
    while True:
        a = a % n
        p += 1
        if d[a]:
            return p - d[a]
        d[a] = p
        a *= 10

print(max(range(1, 1000), key=f))

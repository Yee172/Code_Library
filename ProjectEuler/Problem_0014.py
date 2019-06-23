# Which starting number, under one million,
# produces the longest chain of Collatz Problem?
# ----------------------------------------------------
# Analysis: brute force

from collections import defaultdict

d = defaultdict(int)
d[1] = 1

def dfs(x):
    if d[x] > 0:
        return d[x]
    d[x] = (dfs(3 * x + 1) if x & 1 else dfs(x >> 1)) + 1
    return d[x]

res, maximum = 0, 0
for i in range(2, 10 ** 6):
    m = dfs(i)
    if m > maximum:
        maximum = m
        res = i

print(res)

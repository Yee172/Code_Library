from bisect import bisect as bs
from itertools import accumulate as ac
rd = lambda: map(int, input().split())
n, q = rd()
A, k = rd(), rd()
a = list(ac(A))
d = 0
for i in range(q):
    d += next(k)
    j = bs(a, d)
    if j == n:
        d = 0
        j = 0
    print(n - j)

# If the product of these four two-digit / two-digit
# digit cancelling fractions is given in its
# lowest common terms,
# find the value of the denominator.
# ----------------------------------------------------
# Analysis: brute force

from functools import reduce
from math import gcd
r = []
for i in range(1, 10):
    for j in range(1, 10):
        for k in range(1, 10):
            for l in range(1, 10):
                a = i * 10 + j
                b = k * 10 + l
                if a >= b:
                    continue
                if i == k and j * b == l * a:
                        r.append((a, b))
                elif j == k and i * b == l * a:
                        r.append((a, b))
                elif i == l and j * b == k * a:
                        r.append((a, b))
                elif j == l and i * b == k * a:
                        r.append((a, b))
p, q = zip(*r)
p = reduce(lambda x, y: x * y, p)
q = reduce(lambda x, y: x * y, q)
print(q // gcd(p, q))

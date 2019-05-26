# Let ABCD be a quadrilateral whose vertices are lattice
# points lying on the coordinate axes as follows:
#    A(a, 0), B(0, b), C(−c, 0), D(0, −d),
#    where 1 \leq a, b, c, d \leq m and a, b, c, d, m are integers.
# How many quadrilaterals ABCD strictly contain a square
# number of lattice points for m = 100?
# ----------------------------------------------------
# Analysis: Pick's theorem

from math import gcd

m = 100
edge_point_number = [[0] * (m + 1) for i in range(m + 1)]
for i in range(1, m + 1):
    for j in range(1, m + 1):
        edge_point_number[j][i] = i * j - gcd(i, j)

def is_square(n):
    return int(n ** .5) ** 2 == n

print(sum((2 - (a == c)) * (2 - (b == d)) for a in range(1, m + 1) for c in range(a, m + 1) for b in range(1, m + 1) for d in range(b, m + 1) if is_square(edge_point_number[a][b] + edge_point_number[b][c] + edge_point_number[c][d] + edge_point_number[d][a] + 2 >> 1)))

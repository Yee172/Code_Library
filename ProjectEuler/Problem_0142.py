# Find the smallest x + y + z with integers x > y > z > 0
# such that x + y, x − y, x + z, x − z, y + z, y − z
# are all perfect squares.
# ----------------------------------------------------
# Analysis: brute force
#           Let x + y = A^{2}, x - y = B^{2}
#               y + z = C^{2}, y - z = D^{2}
#               x + z = E^{2}, x - z = F^{2}
#           Then, E^{2} = B^{2} + C^{2}
#                 F^{2} = B^{2} + D^{2}
#                 A^{2} = E^{2} + D^{2}
#                 C and D to be of the same parity

from queue import PriorityQueue
from collections import defaultdict

pq = PriorityQueue()
pq.put((3, 4, 5, 3, 4, 5))
d = defaultdict(list)

def get_res():
    B = 3
    while not pq.empty():
        a, b, c, ad, bd, cd = pq.get()
        d[a].append((b, c))
        d[b].append((a, c))
        if B < a:
            if len(d[B]) > 1:
                for i, (C, E) in enumerate(d[B]):
                    E *= E
                    for j in range(i):
                        D, F = d[B][j]
                        if not C - D & 1:
                            A = D * D + E
                            if int(A ** .5) ** 2 == A:
                                return A + (E - F * F) // 2
            B = a
        if a == ad:
            x, y, z = a - 2 * b + 2 * c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c
            pq.put((x, y, z, x, y, z))
            x, y, z = 2 * a + b + 2 * c, a + 2 * b + 2 * c, 2 * a + 2 * b + 3 * c
            pq.put((x, y, z, x, y, z))
            x, y, z = -2 * a + b + 2 * c, -a + 2 * b + 2 * c, -2 * a + 2 * b + 3 * c
            pq.put((x, y, z, x, y, z))
        pq.put((a + ad, b + bd, c + cd, ad, bd, cd))

print(get_res())

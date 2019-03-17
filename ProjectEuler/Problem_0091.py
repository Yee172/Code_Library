# The points P(x_{1}, y_{1}) and Q(x_{2}, y_{2}) are
# plotted at integer coordinates and are joined to the
# origin, O(0, 0), to form \triangle OPQ.
# Given that 0 \leq x_{1}, y_{1}, x_{2}, y_{2} \leq 50,
# how many right triangles can be formed?
# ----------------------------------------------------
# Analysis: brute force

MAXX = 50 + 1
MAXY = 50 + 1

def is_right_triangle(x1, y1, x2, y2):
    return not all([x1 * x2 + y1 * y2, x1 * (x2 - x1) + y1 * (y2 - y1), x2 * (x1 - x2) + y2 * (y1 - y2)])

r = 0
for y1 in range(1, MAXY):
    for x2 in range(1, MAXX):
        for y2 in range(MAXY):
            r += is_right_triangle(0, y1, x2, y2)

for x1 in range(1, MAXX):
    for y1 in range(MAXY):
        for y2 in range(y1 + 1, MAXY):
            r += is_right_triangle(x1, y1, x1, y2)
        for x2 in range(x1 + 1, MAXX):
            for y2 in range(MAXY):
                r += is_right_triangle(x1, y1, x2, y2)

print(r)

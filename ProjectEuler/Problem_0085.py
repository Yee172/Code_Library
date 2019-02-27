# By counting carefully it can be seen that a rectangular
# grid measuring 3 by 2 contains eighteen rectangles.
# Although there exists no rectangular grid that contains
# exactly two million rectangles, find the area of the
# grid with the nearest solution.
# ----------------------------------------------------
# Analysis: brute force
#           m by n grid contians m * (m + 1) * n * (n + 1) / 4 rectangles

expected = 2 * 10 ** 6
expected_sqrt = int(expected ** .5)
res = 0
delta = 0x3f3f3f3f
for n in range(1, expected_sqrt):
    for m in range(1, expected_sqrt):
        amount = m * (m + 1) * n * (n + 1) >> 2
        if amount > delta + expected:
            break
        d = abs(amount - expected)
        if d < delta:
            delta = d
            res = n * m

print(res)

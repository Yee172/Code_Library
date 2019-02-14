# e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, \ldots, 1, 2k, 1, \ldots].
# The first ten terms in the sequence of convergents
# for e are:
#    2, 3, 8 / 3, 11 / 4, 19 / 7, 87 / 32, 106 / 39,
#    193 / 71, 1264 / 465, 1457 / 536, \ldots
# Find the sum of digits in the numerator of the 100th
# convergent of the continued fraction for e.
# ----------------------------------------------------
# Analysis: brute force

p, q, r, t = 2, 1, 3, 1
for i in range(98):
    if i % 3:
        p, q, r, t = r, t, p + r, q + t
    else:
        m = i // 3 + 1 << 1
        p, q, r, t = r, t, p + m * r, q + m * t

print(sum(map(int, str(r))))

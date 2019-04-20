# A spider, S, sits in one corner of a cuboid room, measuring
# 6 by 5 by 3, and a fly, F, sits in the opposite corner.
# By travelling on the surfaces of the room the shortest
# "straight line" distance from S to F is 10.
# However, there are up to three "shortest" path candidates
# for any given cuboid and the shortest route doesn't always
# have integer length.
# It can be shown that there are exactly 2060 distinct
# cuboids, ignoring rotations, with integer dimensions,
# up to a maximum size of M by M by M, for which the
# shortest route has integer length when M = 100.
# Find the least value of M such that the number of
# solutions first exceeds one million.
# ----------------------------------------------------
# Analysis: brute force

import numba as nb

@nb.njit
def get_res(expected=10 ** 6):
    M = 0
    solution = 0
    while solution <= expected:
        M += 1
        c = M
        for b in range(1, c + 1):
            for a in range(1, b + 1):
                d = (a + b) ** 2 + c ** 2
                if int(d ** .5) ** 2 == d:
                    solution += 1
    return M

print(get_res())

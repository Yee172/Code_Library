# We shall define C(n) to represent the number of cuboids
# that contain n cubes in one of its layers.
# So C(22) = 2, C(46) = 4, C(78) = 5, and C(118) = 8.
# Find the least value of n for which C(n) = 1000.
# ----------------------------------------------------
# Analysis: brute force
#           the cubes in (n + 1)th layer of a * b * c cuboid is
#              2 (a b + a c + b c) + 4 (a + b + c) n + 4 (n - 1) n

import numpy as np
import numba as nb

MAXN = 2 * 10 ** 4
C = np.zeros(MAXN, dtype=np.int64)

@nb.njit
def cube_cover(a, b, c, n):
    x = a * b + a * c + b * c << 1
    y = a + b + c << 2
    return x + y * n + 4 * (n - 1) * n

@nb.njit
def get_res(C):
    for a in range(1, MAXN // 2):
        for b in range(a, MAXN // 2):
            if 2 * a * b + b * b << 1 >= MAXN:
                break
            for c in range(b, MAXN // 2):
                if a * b + a * c + b * c << 1 >= MAXN:
                    break
                n = 0
                while True:
                    now = cube_cover(a, b, c, n)
                    if now >= MAXN:
                        break
                    C[now] += 1
                    n += 1
        if 3 * a ** 2 << 1 >= MAXN:
            break

get_res(C)
print(np.argwhere(C == 1000)[0][0])

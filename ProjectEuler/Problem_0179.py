# Find the number of integers 1 < n < 10^{7}, for which
# n and n + 1 have the same number of positive divisors.
# ----------------------------------------------------
# Analysis: brute force

import numba as nb
import numpy as np

MAXN = 10 ** 7

@nb.njit
def get_res():
    d = np.ones(MAXN + 1, dtype=np.int64)
    for i in range(2, MAXN):
        d[i:MAXN:i] += 1
    return np.sum(np.diff(d[2:]) == 0)

print(get_res())

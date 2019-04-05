# Let t_{k} be the tribonacci numbers.
# For a given integer n, let A_{n} be an array of length n
# (indexed from 0 to n - 1), that is initially filled with zeros.
# The array is changed iteratively by replacing A_{n}[(t_{2 i - 2} \mod{n})]
# with A_{n}[(t_{2 i - 2} \mod{n})] + 2 (t_{2 i - 1} \mod{n}) - n + 1 in each step i.
# After each step i, define M_{n}(i) to be the maximal sum
# of any subsequence of A_{n}.
# Let S(n, l) = \sum_{i = 1}^{l} M_{n}(i).
# Find S(10000003, 10200000) - S(10000003, 10000000).
# ----------------------------------------------------
# Analysis: segment tree
#           PS: use numpy and numba to accelerate

import numba as nb
import numpy as np

n = 10000003
s = 1
while s < n:
    s <<= 1
s <<= 2
x, y, z = 0, 0, 1
a = np.zeros(n, dtype=np.int64)
tree = np.zeros((s, 4), dtype=np.int64)

@nb.njit
def initialize(a, x, y, z):
    for _ in range(10000000):
        a[x] += 2 * y - n + 1
        x, y, z = z, (x + y + z) % n, (x + 2 * y + 2 * z) % n
    return x, y, z

@nb.njit
def merge(left_node, right_node):
    # summation, maximum_prefix, maximum_suffix, maximum_summation
    return left_node[0] + right_node[0],\
           max(left_node[0] + right_node[1], left_node[1]),\
           max(left_node[2] + right_node[0], right_node[2]),\
           max(left_node[2] + right_node[1], left_node[3], right_node[3])

@nb.njit
def build(tree, left, right, index):
    if left == right:
        tree[index] = a[left - 1]
    else:
        middle = left + right >> 1
        build(tree, left, middle, index << 1)
        build(tree, middle + 1, right, index << 1 | 1)
        tree[index] = merge(tree[index << 1], tree[index << 1 | 1])

@nb.njit
def update(tree, left, right, index, delta_index, delta):
    if left == right:
        tree[index] += delta
    else:
        middle = left + right >> 1
        if middle < delta_index:
            update(tree, middle + 1, right, index << 1 | 1, delta_index, delta)
        else:
            update(tree, left, middle, index << 1, delta_index, delta)
        tree[index] = merge(tree[index << 1], tree[index << 1 | 1])

r = 0
x, y, z = initialize(a, x, y, z)
build(tree, 1, n, 1)

for _ in range(200000):
    update(tree, 1, n, 1, x + 1, 2 * y - n + 1)
    x, y, z = z, (x + y + z) % n, (x + 2 * y + 2 * z) % n
    r += tree[1, 3]

print(r)

# Find the minimal path sum, from the top left to
# the bottom right by only moving right and down.
# ----------------------------------------------------
# Analysis: dynamic programming

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p081_matrix.txt'
with open(PROBLEM_FILE, 'r') as f:
    a = list(map(lambda x: list(map(int, x.split(','))), f.read().split()))

n = 80
val = [[0x3f3f3f3f] * n for i in range(n)]
val[0][0] = a[0][0]
for i in range(n):
    for j in range(n):
        v = a[i][j]
        if i > 0:
            val[i][j] = min(val[i][j], val[i - 1][j] + v)
        if j > 0:
            val[i][j] = min(val[i][j], val[i][j - 1] + v)

print(val[n - 1][n - 1])


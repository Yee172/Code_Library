# Find the minimal path sum, from the left column to
# the right column by only moving up, down, and right.
# ----------------------------------------------------
# Analysis: dynamic programming

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p082_matrix.txt'
with open(PROBLEM_FILE, 'r') as f:
    a = list(map(lambda x: list(map(int, x.split(','))), f.read().split()))

n = 80

s = [[0] * n for i in range(n)]
for i in range(1, n):
    s[0][i] = a[0][i]
    for j in range(1, n):
        s[j][i] = s[j - 1][i] + a[j][i]

val = [[0x3f3f3f3f] * n for i in range(n)]
for i in range(n):
    val[i][0] = a[i][0]
for i in range(1, n):
    for j in range(n):
        for k in range(n):
            if k < j:
                val[j][i] = min(val[j][i], val[k][i - 1] + s[j][i] - s[k][i] + a[k][i])
            else:
                val[j][i] = min(val[j][i], val[k][i - 1] + s[k][i] - s[j][i] + a[j][i])

res = 0x3f3f3f3f
for i in range(n):
    res = min(res, val[i][n - 1])

print(res)

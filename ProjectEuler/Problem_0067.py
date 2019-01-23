# Find the maximum total from top to bottom.
# ----------------------------------------------------
# Analysis: dynamic programming

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p067_triangle.txt'
with open(PROBLEM_FILE, 'r') as f:
    a = list(map(lambda x: list(map(int, x.split(' '))), f.read().strip().split('\n')))

res = [a[0][0]]
for i in range(1, len(a)):
    res.append(res[-1])
    for j in range(i, -1, -1):
        if j < i and j:
            res[j] = max(res[j - 1], res[j]) + a[i][j]
        else:
            res[j] += a[i][j]

print(max(res))

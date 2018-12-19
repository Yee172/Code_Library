# Find the minimal path sum, from the top left to
# the bottom right.
# ----------------------------------------------------
# Analysis: Dijkstra algorithm

from queue import PriorityQueue

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p083_matrix.txt'
with open(PROBLEM_FILE, 'r') as f:
    a = list(map(lambda x: list(map(int, x.split(','))), f.read().split()))

n = 80
q = PriorityQueue()
vis = [[False] * n for i in range(n)]
val = [[0x3f3f3f3f] * n for i in range(n)]
val[0][0] = a[0][0]
q.put((val[0][0], 0, 0))
while not q.empty():
    v, x, y = q.get()
    if vis[x][y]:
        continue
    vis[x][y] = True
    v = val[x][y]
    if x > 0:
        if val[x - 1][y] > v + a[x - 1][y]:
            val[x - 1][y] = v + a[x - 1][y]
            q.put((val[x - 1][y], x - 1, y))
    if x + 1 < n:
        if val[x + 1][y] > v + a[x + 1][y]:
            val[x + 1][y] = v + a[x + 1][y]
            q.put((val[x + 1][y], x + 1, y))
    if y > 0:
        if val[x][y - 1] > v + a[x][y - 1]:
            val[x][y - 1] = v + a[x][y - 1]
            q.put((val[x][y - 1], x, y - 1))
    if y + 1 < n:
        if val[x][y + 1] > v + a[x][y + 1]:
            val[x][y + 1] = v + a[x][y + 1]
            q.put((val[x][y + 1], x, y + 1))

print(val[n - 1][n - 1])


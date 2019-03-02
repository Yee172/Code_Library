# A file file containing the co-ordinates of one thousand
# "random" triangles, find the number of triangles for
# which the interior contains the origin.
# ----------------------------------------------------
# Analysis: brute force

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p102_triangles.txt'
with open(PROBLEM_FILE, 'r') as f:
    triangles = map(lambda a: list(map(int, a.split(','))), f.read().strip().split())

class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __cross__(self, another):
        return self.x * another.y - another.x * self.y

def is_contain_origin(t):
    v = [Vector2D(x, y) for x, y in zip(t[0::2], t[1::2])]
    r = [v[i].__cross__(v[(i + 1) % len(v)]) for i in range(len(v))]
    return all(x > 0 for x in r) or all(x < 0 for x in r)

print(sum(map(is_contain_origin, triangles)))

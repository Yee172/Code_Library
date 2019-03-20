# A file file containing a network with forty vertices,
# and given in matrix form, find the maximum saving
# which can be achieved by removing redundant edges
# whilst ensuring that the network remains connected.
# ----------------------------------------------------
# Analysis: Kruskal algorithm

from lib.disjoint_set_union import disjoint_set_union

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p107_network.txt'
with open(PROBLEM_FILE, 'r') as f:
    network = list(map(lambda a: list(map(lambda x: 0 if x == '-' else int(x), a.split(','))), f.read().strip().split()))

l = len(network)
dsu = disjoint_set_union(l)
edges = sorted([(network[i][j], i, j) for i in range(l) for j in range(i + 1, l) if network[i][j]])
redundant = 0

for value, i, j in edges:
    if dsu.get_father(i) != dsu.get_father(j):
        dsu.union_father(i, j)
    else:
        redundant += value

print(redundant)

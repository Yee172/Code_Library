from itertools import groupby
input()
print(['YES', 'NO'][len(set(len(list(g)) for k, g in groupby(input().split()))) > 1])

from math import sqrt
read = lambda: map(int, input().split())
n = int(input())
a = list(read())
a.sort()
r = 0
for _ in a:
    if _ < 0:
        r = _
        continue
    __ = sqrt(_)
    if __ != int(__):
        r = _
print(r)

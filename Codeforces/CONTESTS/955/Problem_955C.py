from sys import stdin
from math import sqrt as s
from bisect import bisect as f
rl = lambda l: tuple(map(int, l.split()))
a = []
m = 10 ** 18
for i in range(2, 10 ** 6):
    j = i * i
    k = j * i
    while k < m:
        a.append(k)
        k *= j
b = [x for x in a if not s(x).is_integer()]
b.sort()
a = [b[0]]
for x in b:
    if x != a[-1]:
        a.append(x)
input()
b = list(map(rl, stdin.readlines()))
def g(x):
    p = int(s(x))
    p -= p * p > x
    return p
o = []
for l, r in b:
    o.append(f(a, r) - f(a, l - 1) + g(r) - g(l - 1))
print('\n'.join(map(str, o)))

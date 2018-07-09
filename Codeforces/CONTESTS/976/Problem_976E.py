from sys import stdin
rd = lambda l: tuple(map(int, l.split()))
n, a, b = rd(input())
b = min(b, n)
p = list(map(rd, stdin.readlines()))
f = lambda x: max(0, x[0] - x[1])
g = lambda x: (x[0] << a) - x[1]
s = sum(x[1] for x in p)
e = 0
if b:
    p.sort(key=f, reverse=True)
    t = sum(f(x) for x in p[:b])
    for i in range(b):
        e = max(e, t - f(p[i]) + g(p[i]))
    for i in range(b, n):
        e = max(e, t - f(p[b - 1]) + g(p[i]))
print(s + e)

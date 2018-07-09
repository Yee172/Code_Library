rd = lambda: list(map(int, input().split()))
n, b = rd()
a, y, p, l = rd(), [], 0, 0
for x in a:
    if not p:
        y.append(abs(x - l))
    p += [-1, 1][x & 1]
    if not p:
        l = x
g = sorted(y[1:])
x, r = 0, 0
for p in g:
    x += p
    if x > b:
        break
    r += 1
print(r)

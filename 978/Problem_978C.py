rd = lambda: map(int, input().split())
n, m = rd()
a = rd()
b = rd()
s = 0
f = 0
l = 0
for x in b:
    while s < x:
        l = s
        s += next(a)
        f += 1
    print(f, x - l)

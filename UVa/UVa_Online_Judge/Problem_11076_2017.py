f = lambda x: x * f(x - 1) if x else 1
while 1:
    n = int(input())
    if not n:
        break
    a = {}
    for x in map(int, input().split()):
        a[x] = a.get(x, 0) + 1
    t = f(n - 1)
    s = 1
    for x in a.values():
        s *= f(x)
    print(int('1' * n) * sum(t // (s // a[x]) * x for x in a))

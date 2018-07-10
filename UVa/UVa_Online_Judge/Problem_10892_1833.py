def gff(n):
    d = 2
    while d * d <= n:
        while n % d is 0:
            yield d
            n //= d
        d += 1
    if n > 1:
        yield n
while 1:
    n = int(input())
    if not n:
        break
    a = {}
    r = 1
    for x in gff(n):
        a[x] = a.get(x, 0) + 1
    for x in a.values():
        r *= 2 * x + 1
    print(n, r // 2 + 1)

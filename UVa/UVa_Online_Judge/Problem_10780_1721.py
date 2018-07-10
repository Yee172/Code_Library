def gff(n):
    d = 2
    while d * d <= n:
        while n % d is 0:
            yield d
            n //= d
        d += 1
    if n > 1:
        yield n
t = int(input())
for _ in range(t):
    m, n = map(int, input().split())
    print('Case %d:' % (_ + 1))
    a = {}
    for x in gff(m):
        a[x] = a.get(x, 0) + 1
    b = {}
    for x in a:
        i = x
        b[x] = 0
        while i <= n:
            b[x] += n // i
            i *= x
    r = min(b[x] // a[x] for x in a)
    print(r if r else 'Impossible to divide')

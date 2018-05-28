def gf(n):
    d = 2
    while d * d <= n:
        f = 1
        while n % d is 0:
            if f:
                yield d
            f = 0
            n //= d
        d += 1
    if n > 1:
        yield n
x2 = int(input())
print(min(x1 - p + 1 for x1 in range(x2 - max(gf(x2)) + 1, x2 + 1) for p in gf(x1) if p != x1))


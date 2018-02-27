n, k, a, b = [int(input()) for i in range(4)]
r = 0
if k - 1:
    while n:
        m, t = divmod(n, k)
        r += t * a
        n -= t
        r += min(b, (n - m) * a)
        n = m
else:
    r += n * a
print(r - a)

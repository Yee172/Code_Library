from bisect import bisect_left as bs
rd = lambda: map(int, input().split())
n, k = rd()
r = list(rd())
a = sorted(r)
d = [0] * n
for _ in range(k):
    x, y = rd()
    x -= 1
    y -= 1
    p = r[x] - r[y]
    if p < 0:
        d[y] += 1
    if p > 0:
        d[x] += 1
print(*map(lambda x: bs(a, r[x]) - d[x], range(n)))

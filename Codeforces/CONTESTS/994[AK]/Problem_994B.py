import heapq as q
rd = lambda: map(int, input().split())
n, k = rd()
a = sorted(zip(rd(), rd(), range(n)))
r = [0] * n
h = []
s = 0
for x, y, z in a:
    s += y
    r[z] = s
    q.heappush(h, y)
    if len(h) > k:
        s -= q.heappop(h)
print(*r)

rd = lambda: map(int, input().split())
n, k = rd()
a = rd()
d = {}
for i in range(n):
    d[next(a)] = i + 1
if len(d) < k:
    print('NO')
else:
    print('YES')
    print(*list(d.values())[:k])

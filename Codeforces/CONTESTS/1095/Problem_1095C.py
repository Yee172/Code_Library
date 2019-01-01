n, k = map(int, input().split())
a = bin(n)[:1:-1]
d = dict()
m = 0
for i, x in enumerate(a):
    d[1 << i] = x == '1'
    m += d[1 << i]
if k > n or k < m:
    print('NO')
    exit()
print('YES')
while m < k:
    p = k - m
    g = min(d[1 << i], p)
    d[1 << i] -= g
    i -= 1
    d[1 << i] += 2 * g
    m += g
r = []
for x in d:
    r += [x] * d[x]
print(*r)

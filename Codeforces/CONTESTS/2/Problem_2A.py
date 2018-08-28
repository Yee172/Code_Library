d, p = {}, []
for _ in range(int(input())):
    n, s = input().split()
    d[n] = d.get(n, 0) + int(s)
    p.append((d[n], n))
m = max(d.values())
print(next(n for s, n in p if s >= m and d[n] >= m))

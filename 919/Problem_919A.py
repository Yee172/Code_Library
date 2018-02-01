read = lambda: map(int, input().split())
n, m = read()
c = []
for _ in range(n):
    a, b = read()
    c.append(a / b)
print(min(c) * m)

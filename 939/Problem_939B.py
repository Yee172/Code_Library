rd = lambda: map(int, input().split())
n, k = rd()
p, q = min(enumerate(rd()), key=lambda x: n % x[1])
print(p + 1, n // q)

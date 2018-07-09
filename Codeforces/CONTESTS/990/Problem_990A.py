n, m, a, b = map(int, input().split())
n %= m
print(min(n * b, (m - n) * a))

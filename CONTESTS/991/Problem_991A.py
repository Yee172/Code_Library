a, b, c, n = map(int, input().split())
r = n - a - b + c
print(-1 if r < 1 or a < c or b < c else r)

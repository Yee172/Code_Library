rd = lambda: map(int, input().split())
h, m = rd()
t = h * 60 + m
h, d, c, n = rd()
h += n - 1
print(min(h // n, (max(0, 1200 - t) * d + h) // n * .8) * c)

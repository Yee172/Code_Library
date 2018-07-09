rd = lambda: map(int, input().split())
n, a, b, c, t = rd()
print(sum(map(lambda x: (t - x) * (c - b) + a, rd())) if c > b else a * n)

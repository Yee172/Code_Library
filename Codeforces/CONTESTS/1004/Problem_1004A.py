rd = lambda: list(map(int, input().split()))
n, d = rd()
a = rd()
print(2 + sum([2 - (y - x == 2 * d), 0][y - x < 2 * d] for x, y in zip(a, a[1:])))

rd = lambda: map(int, input().split())
n, d = rd()
for _ in range(int(input())):
    x, y = rd()
    x, y = y + x, y - x
    print(['NO', 'YES'][d <= x <= 2 * n - d and -d <= y <= d])

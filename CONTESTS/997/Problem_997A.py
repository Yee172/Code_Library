n, x, y = map(int, input().split())
p = len(input().replace('1', ' ').split())
print([0, (p - 1) * min(x, y) + y][p > 0])

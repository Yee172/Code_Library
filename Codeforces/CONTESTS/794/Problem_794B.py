n, h = map(int, input().split())
for i in range(1, n):
    print(h / (n / i) ** .5)

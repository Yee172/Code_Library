rd = lambda: list(map(int, input().split()))
n, k = rd()
a = [1] + sorted(rd())
print(a[k] if n == k or a[k + 1] - a[k] else -1)

rd = lambda: map(int, input().split())
n, d = rd()
a = sorted(list(rd()))
print(n - max(j - i + 1 for i in range(n) for j in range(i, n) if a[j] - a[i] <= d))

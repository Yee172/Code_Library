rd = lambda: list(map(int, input().split()))
n, k = rd()
a = rd()
i, j = 0, n - 1
while i <= j and a[i] <= k:
    i += 1
while i < j and a[j] <= k:
    j -= 1
print(n - j + i - 1)

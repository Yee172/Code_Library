rd = lambda: map(int, input().split())
n, k, l = rd()
a = sorted(rd())
for i in range(n * k):
    if a[i] - a[0] > l:
        break
else:
    i += 1
j, s = 0, 0
while j < i:
    s += a[j]
    n -= 1
    j = max(min(i - n, j + k), j + 1)
print([s, 0][n > 0])

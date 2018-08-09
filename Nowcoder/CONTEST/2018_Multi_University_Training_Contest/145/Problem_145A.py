n = int(input())
a = [-1] * n
for i in range(n - 1, 0, -1):
    if a[i] >= 0:
        continue
    j = ~i & (1 << len(bin(i)) - 2) - 1
    a[i] = j
    a[j] = i
a[0] = [a[0], 0][a[0] < 0]
print(*a)

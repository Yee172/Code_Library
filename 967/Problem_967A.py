rd = lambda: map(int, input().split())
n, s = rd()
a = [- s - 1]
for _ in range(n):
    h, m = rd()
    a.append(h * 60 + m)
x = 0
for i in range(1, len(a)):
    if a[i] - a[i - 1] > 2 * s + 1:
        break
    x = a[i] + s + 1
print(*divmod(x, 60))
